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

const int N = 100456;

int n, m;

struct Edge {
    int dest;
    int tag;
};


vector<Edge> g[N];
vector<bool> visited;
vector<int> vs;

int dfs(int cur, int vt, vector<int>& path) {
    assert(vs[cur] != -1);
    if (vs[cur] == 1) {
        path.push_back(cur);
    }
    int res = vs[cur];
    for (const auto& e : g[cur]) {
        int v = e.tag ^ vt;
        int nxt = e.dest;
        int vn = v ^ vs[cur];
        if (vs[nxt] != -1) {
            if (vs[nxt] != vn) {
                return INF;
            }
        } else {
            vs[nxt] = vn;
            res += dfs(nxt, vt, path);
        }
        if (res >= INF) {
            return INF;
        }
    }

    return res;
}

void dfs1(int cur, vector<int>& sub) {
    visited[cur] = true;
    sub.push_back(cur);
    for (const auto& e : g[cur]) {
        int nxt = e.dest;
        if (!visited[nxt]) {
            dfs1(nxt, sub);
        }
    }
}

int main() {
    input(n, m);

    int a, b;
    char color[5];
    for (int i = 0; i < m; i++) {
        scanf("%d%d%s", &a, &b, color);
        g[a].push_back({b, color[0] == 'B'});
        g[b].push_back({a, color[0] == 'B'});
    }

    vector<int> tots[2];

    bool valids[2] = { true, true };
    vs = vector<int>(N, -1);

    for (int vt = 0; vt <= 1; vt++) {
        vector<int>& tot = tots[vt];
        bool& valid = valids[vt];

        visited = vector<bool>(N, false);

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                continue;
            }
            vector<int> sub;
            dfs1(i, sub);

            int res = INF;
            vector<int> path;
            for (int v1 = 0; v1 <= 1; v1++) {
                vector<int> path_;
                for (const auto& node : sub) {
                    vs[node] = -1;
                }
                vs[i] = v1;
                int u = dfs(i, vt, path_);
                // print(i, u);
                if (u < res) {
                    res = u;
                    path = path_;
                }
            }

            if (res >= INF) {
                valid = false;
                break;
            }
            copy(path.begin(), path.end(), back_inserter(tot));
        }
    }

    if (valids[0] || valids[1]) {
        vector<int> tot;
        if (valids[0]) {
            tot = tots[0];
        }
        if (valids[1]) {
            if (!valids[0]) {
                tot = tots[1];
            } else {
                if (tots[1].size() < tot.size()) {
                    tot = tots[1];
                }
            }
        }
        print(tot.size());
        for (auto node : tot) {
            printf("%d ", node);
        }
        puts("");
    } else {
        print(-1);
    }
    return 0;
}

/*

^^^TEST^^^
3 3
1 2 B
3 1 R
3 2 B
-----
1
2
$$$TEST$$$

^^^TEST^^^
6 5
1 3 R
2 3 R
3 4 B
4 5 R
4 6 R
-----
2
3 4
$$$TEST$$$

^^^TEST^^^
4 5
1 2 R
1 3 R
2 3 B
3 4 B
1 4 B
-----
-1
$$$TEST$$$

*/
