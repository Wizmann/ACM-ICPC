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
#include <cassert>

using namespace std;

typedef long long llint;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

const int Q = 10000;

char buf1[22];
char buf2[22];


class Hungary {
public:
    Hungary(int left_, int right_) {
        left = left_;
        right = right_;

        g = vector<vector<int> >(left);
        for (int i = 0; i < left; i++) {
            g[i] = vector<int>(right, 0);
        }
    }
    
    int match() {
        pre = vector<int>(right, -1);
        int res = 0;
        for (int i = 0; i < left; i++) {
            visited = vector<bool>(right, false);
            if (dfs(i)) {
                res++;
            }
        }
        return res;
    }

    bool dfs(int cur) {
        for (int i = 0; i < right; i++) {
            if (g[cur][i] && !visited[i]) {
                visited[i] = true;
                if (pre[i] == -1) {
                    pre[i] = cur;
                    return true;
                } else if (dfs(pre[i])) {
                    pre[i] = cur;
                    return true;
                }
            }
        }
        return false;
    }

    void addEdge(int l, int r) {
        g[l][r] = 1;
    }

    void removeEdge(int l, int r) {
        g[l][r] = 0;
    }
private:
    int left, right;
    vector<vector<int> > g;

    vector<bool> visited;
    vector<int> pre;
};

int main()
{
    int T;
    input(T);
    for (int case_ = 0; case_ < T; case_++) {
        int u;
        input(u);

        vector<pair<int, int> > ps(10, {0, 9});
        map<char, int> mp;
        map<int, char> rmp;
        vector<int> freq(10, 0);

        int idx = 0;
        for (int i = 0; i < Q; i++) {
            scanf("%s%s", buf1, buf2);

            for (auto c: string(buf2)) {
                if (mp.count(c) == 0) {
                    mp[c] = idx;
                    rmp[idx] = c;
                    idx++;
                }
            }
            int u = mp[buf2[0]];
            freq[u]++;
            ps[u].first = max(ps[u].first, 1);
            if (string(buf1) != "-1") {
                if (strlen(buf1) == strlen(buf2)) {
                    int v = buf1[0] - '0';
                    ps[u].first = max(ps[u].first, 1);
                    ps[u].second = min(ps[u].second, v);
                }
            }
        }

        auto h = Hungary(10, 10);
        for (int i = 0; i < 10; i++) {
            for (int j = ps[i].first; j <= ps[i].second; j++) {
                h.addEdge(i, j);
            }
        }
        const int maxm = h.match();

        vector<int> res(10, -1);

        for (int i = 0; i < 10; i++) {
            for (int j = ps[i].first; j <= ps[i].second; j++) {
                h.removeEdge(i, j);

                int m = h.match();
                if (m != maxm) {
                    res[i] = j;
                    for (int k = 0; k < 10; k++) {
                        h.removeEdge(i, k);
                    }
                    h.addEdge(i, j);
                    break;
                }

                h.addEdge(i, j);
            }
        }

        string output = "0123456789";
        for (int i = 0; i < 10; i++) {
            // printf("%c %d\n", rmp[i], res[i]);
            char c = rmp[i];
            if (res[i] == -1) {
                continue;
            }
            output[res[i]] = rmp[i];
        }

        vector<pair<int, char> > fp;
        for (int i = 0; i < 10; i++) {
            if (rmp[i] == output[0]) {
                continue;
            }
            fp.push_back({-freq[i], rmp[i]});
        }
        sort(fp.begin(), fp.end());

        for (int i = 0, j = 0; i < 10; i++) {
            if ('0' <= output[i] && output[i] <= '9') {
                output[i] = fp[j].second;
                j++;
            }
        }

        printf("Case #%d: ", case_ + 1);
        puts(output.c_str());
    }

    return 0;
}

