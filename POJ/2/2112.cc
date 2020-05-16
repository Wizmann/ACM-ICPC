#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

typedef long long llint;

class MultiHungary {
public:
    MultiHungary(int left_, int right_) : left(left_), right(right_) {
        g = vector<vector<int> >(left);
        for (int i = 0; i < left; i++) {
            g[i] = vector<int>(right, 0);
        }
        caps = vector<int>(right, 0);
    }

    void setCapacity(int idx, int cap) {
        caps[idx] = cap;
    }

    void addEdge(int l, int r) {
        g[l][r] = 1;
    }
    

    // `all_match` indicates if all nodes on the left 
    // are matched with one of the right nodes
    int match(bool& match_all_left, bool must_match_all_left) {
        int res = 0;
        match_all_left = true;
        pre = vector<vector<int> >(right);
        for (int i = 0; i < left; i++) {
            visited = vector<bool>(right, false);
            if (find_path(i)) {
                res++;
            } else {
                match_all_left = false;
            }

            if (must_match_all_left && !match_all_left) {
                return -1;
            }
        }

        return res;
    }
private:
    bool find_path(int cur) {
        for (int i = 0; i < right; i++) {
            if (g[cur][i] && !visited[i]) {
                visited[i] = true;
                if (pre[i].size() < caps[i]) {
                    pre[i].push_back(cur);
                    return true;
                }
                for (int j = 0; j < pre[i].size(); j++) {
                    int& p = pre[i][j];
                    if (find_path(p)) {
                        p = cur;
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    int left, right;
    vector<vector<int> > g;
    vector<int> caps;
    vector<vector<int> > pre;
    vector<bool> visited;
};

const int SIZE = 300;
const int INF = 0x3f3f3f3f;

int g[SIZE][SIZE];

int main() {
    int k, c, m;
    scanf("%d%d%d", &k, &c, &m);

    memset(g, INF, sizeof(g));

    int n = k + c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
            if (g[i][j] == 0) {
                g[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
            }
        }
    }

    int l = 0;
    int r = INF;

    while (l <= r) {
        MultiHungary mh(c, k);
        for (int i = 0; i < k; i++) {
            mh.setCapacity(i, m);
        }
        int mid = (l + r) >> 1;
        for (int i = 0; i < k; i++) {
            for (int j = k; j < n; j++) {
                if (g[i][j] <= mid) {
                    mh.addEdge(j - k, i);
                }
            }
        }

        bool all_match = true;
        int match = mh.match(all_match, true);

        // printf("%d, %d\n", all_match, match);

        if (all_match) {
            assert(match == c);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    printf("%d\n", l);

    return 0;
}


