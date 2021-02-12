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
#include <queue>

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

const int SIZE = 2222;

struct Edge {
    int dest, cost;
};

int n, m;
int dp[SIZE][SIZE];
vector<Edge> g[SIZE];
vector<bool> visited;

void spfa(int st, int* dis) {
    visited = vector<bool>(n + 1, false);
    queue<int> q;
    q.push(st);
    int pre = dis[st];
    dis[st] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        visited[cur] = false;

        for (const auto& p : g[cur]) {
            int nxt = p.dest;
            int cost = p.cost;

            if (dis[nxt] > dis[cur] + cost) {
                dis[nxt] = dis[cur] + cost;
                if (!visited[nxt]) {
                    q.push(nxt);
                    visited[nxt] = true;
                }
            }
        }
    }
    dis[st] = pre;
}

int main() {
    input(n, m);
    memset(dp, INF, sizeof(dp));

    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back({b, c});
        if (a == b) {
            dp[a][a] = min(dp[a][a], c);
        }
    }

    for (int i = 1; i <= n; i++) {
        spfa(i, dp[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            dp[i][i] = min(dp[i][i], dp[i][j] + dp[j][i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i][i] >= INF) {
            puts("-1");
        } else {
            printf("%d\n", dp[i][i]);
        }
    }

    return 0;
}

/*

^^^TEST^^^
4 4
1 2 5
2 3 10
3 1 15
4 3 20
-----
30
30
30
-1
$$$TEST$$$

^^^TEST^^^
4 6
1 2 5
1 3 10
2 4 5
3 4 10
4 1 10
1 1 10
-----
10
20
30
20
$$$TEST$$$

^^^TEST^^^
4 7
1 2 10
2 3 30
1 4 15
3 4 25
3 4 20
4 3 20
4 3 30
-----
-1
-1
40
40
$$$TEST$$$

*/
