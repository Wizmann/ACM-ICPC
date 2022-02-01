#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

class DisjointSet {
public:
    DisjointSet() {}
    DisjointSet(int n_) : n(n_), father(n), size(n) {
        for (int i = 0; i < n; i++) {
            father[i] = i;
            size[i] = 1;
        }
    }

    void make_union(int a, int b) {
        int fa = find_father(a);
        int fb = find_father(b);

        if (fa == fb) {
            return;
        }

        father[fb] = fa;
        size[fa] += size[fb];
    }

    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }

    int get_size(int a) {
        int f = find_father(a);
        return size[f];
    }
private:
    int n;
    vector<int> father;
    vector<int> size;
};

const int SIZE = 212345;

vector<pair<int, int> > same;
vector<pair<int, int> > opp;

vector<int> visited;
vector<int> g[SIZE];

int dfs(DisjointSet& ds, int pre, int cur, vector<int> groups[2], int p) {
    if (visited[cur] != -1) {
        if (visited[cur] == p) {
            return 0;
        }
        return -1;
    }
    visited[cur] = p;
    groups[p].push_back(cur);
    for (int i = 0; i < (int)g[cur].size(); i++) {
        int nxt = g[cur][i];
        if (nxt == pre) {
            continue;
        }

        int res = dfs(ds, cur, nxt, groups, p ^ 1);
        if (res == -1) {
            return -1;
        }
    }
    return 0;
}

int main() {
    int T;
    input(T);
    while (T--) {
        int n, m;
        input(n, m);

        for (int i = 0; i < SIZE; i++) {
            g[i].clear();
        }

        char buffer[123];
        DisjointSet ds(n + 1);

        vector<pair<int, int> > opps;

        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%s", &a, &b, buffer);
            if (buffer[0] == 'i') {
                opps.push_back({a, b});
            } else {
                ds.make_union(a, b);
            }
        }

        for (auto& p : opps) {
            int fa = ds.find_father(p.first);
            int fb = ds.find_father(p.second);
            g[fa].push_back(fb);
            g[fb].push_back(fa);
        }

        visited = vector<int>(n + 1, -1);

        int res = 0;
        for (int i = 1; i <= n; i++) {
            int f = ds.find_father(i);
            if (visited[f] != -1) {
                continue;
            }
            if (g[f].size() == 0) {
                continue;
            }
            vector<int> groups[2];
            int ret = dfs(ds, -1, f, groups, 0);
            if (ret == -1) {
                res = -1;
                break;
            }

            for (int j = 0; j < 2; j++) {
                int m = groups[j].size();
                for (int k = 1; k < m; k++) {
                    ds.make_union(groups[j][k], groups[j][k - 1]);
                }
            }

            a = ds.find_father(groups[0][0]);
            b = ds.find_father(groups[1][0]);
            if (a == b) {
                res = -1;
                break;
            }

            res += max(ds.get_size(a), ds.get_size(b));
        }

        for (int i = 1; i <= n && res >= 0; i++) {
            int f = ds.find_father(i);
            if (visited[f] != -1) {
                continue;
            }
            // print(">>", i, ds.get_size(i));
            res += ds.get_size(f);
            visited[f] = 2;
        }

        print(res);
    }

    return 0;
}

/*

^^^TEST^^^
2
5 1
1 3 crewmate
5 2
1 2 imposter
1 3 imposter
-----
5
4
$$$TEST$$$

^^^TEST^^^
5
3 2
1 2 imposter
2 3 crewmate
5 4
1 3 crewmate
2 5 crewmate
2 4 imposter
3 4 imposter
2 2
1 2 imposter
2 1 crewmate
3 5
1 2 imposter
1 2 imposter
3 2 crewmate
3 2 crewmate
1 3 imposter
5 0
-----
2
4
-1
2
5
$$$TEST$$$

*/
