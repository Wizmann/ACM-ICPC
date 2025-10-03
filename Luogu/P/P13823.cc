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

const int SIZE = 512345;

struct Edge {
    int dest;
    int cost;
};

vector<int> ns;
vector<Edge> g[SIZE * 2];
vector<int> maxi;

vector<bool> visited;
vector<int> dp;

int dfs1(int pre, int cur, vector<int>& path) {
    visited[cur] = true;
    path.push_back(cur);
    int maxi = ns[cur];
    for (auto e : g[cur]) {
        int nxt = e.dest;
        if (nxt == pre) {
            continue;
        }
        if (!visited[nxt]) {
            maxi = max(maxi, dfs1(cur, nxt, path));
        }
    }
    return maxi;
}

void bfs1(deque<int>& q) {
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();

        for (auto e : g[cur]) {
            int nxt = e.dest;
            int cost = e.cost;
            if (dp[nxt] > dp[cur] + cost) {
                dp[nxt] = dp[cur] + cost;
                if (cost == 0) {
                    q.push_front(nxt);
                } else {
                    q.push_back(nxt);
                }
            }
        }
    }
}

int main() {
    int n, m;
    input(n, m);

    ns.resize(n * 2 + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
        ns[i + n] = ns[i];
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        if (a == b) {
            continue;
        }
        g[a].push_back({b, 0});
        g[b + n].push_back({a + n, 0});
        g[a].push_back({a + n, 1});
        g[a + n].push_back({a, 1});
        g[b].push_back({b + n, 1});
        g[b + n].push_back({b, 1});
    }

    visited = vector<bool>(n * 2 + 1, false);
    dp = vector<int>(n * 2 + 1, INF);
    maxi = vector<int>(n * 2 + 1, -1);
    for (int i = 1; i <= n * 2; i++) {
        if (visited[i]) {
            continue;
        }
        vector<int> path;
        deque<int> q;
        path.reserve(n * 2 + 1);
        int top = dfs1(-1, i, path);
        for (auto node : path) {
            if (ns[node] == top) {
                q.push_back(node);
                dp[node] = 1;
            }
            maxi[node] = top;
        }

        bfs1(q);
    }

    for (int i = 1; i <= n; i++) {
        int mini = min(dp[i], dp[i + n]);
        if (maxi[i] == ns[i]) {
            printf("0 ");
        } else {
            printf("%d ", mini);
        }
    }
    puts("");

    return 0;
}

/*

^^^TEST^^^
2 1
1 100
1 2
-----
1 0
$$$$TEST$$$

^^^TEST^^^
2 1
1 100
2 1
-----
1 0
$$$$TEST$$$

^^^TEST^^^
2 1
100 100
2 1
-----
0 0
$$$$TEST$$$

^^^TEST^^^
5 4
1 2 3 4 555
1 3
2 3
3 5
4 5
-----
1 1 1 1 0
$$$$TEST$$$

^^^TEST^^^
6 5
1 1 4 5 1 4
1 2
2 1
3 4
4 5
3 5
-----
0 0 1 0 1 0
$$$TEST$$$

^^^TEST^^^
9 7
2 3 6 16 4 17 15 3 9 
1 9
5 2
3 6
4 2
9 8
2 1
5 6
-----
2 2 1 3 1 0 0 2 2
$$$TEST$$$

*/
