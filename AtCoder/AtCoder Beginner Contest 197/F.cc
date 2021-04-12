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

const int N = 1234;
const int ALPHA = 26;

int n, m;
int dp[N][N];

vector<int> g[ALPHA][N];

int main() {
    input(n, m);

    memset(dp, INF, sizeof(dp));

    int a, b;
    char c[10];

    queue<pair<int, int> > q;
    for (int i = 1; i <= n; i++) {
        q.push({i, i});
        dp[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d%s", &a, &b, c);
        int cc = c[0] - 'a';
        g[cc][a].push_back(b);
        g[cc][b].push_back(a);

        if (a != b) {
            q.push({a, b});
            dp[a][b] = dp[b][a] = 1;
        }
    }

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int l = p.first;
        int r = p.second;

        for (int i = 0; i < ALPHA; i++) {
            for (const auto& nxt1 : g[i][l]) {
                for (const auto& nxt2 : g[i][r]) {
                    if (dp[nxt1][nxt2] > dp[l][r] + 2) {
                        dp[nxt2][nxt1] = dp[nxt1][nxt2] = dp[l][r] + 2;
                        q.push({nxt1, nxt2});
                    }
                }
            }
        }
    }

    int res = dp[1][n];

    if (res >= INF) {
        puts("-1");
    } else {
        print(res);
    }

    return 0;
}

/*
^^^TEST^^^
4 4
1 2 b
2 4 a
1 3 a
3 4 b
---
-1
$$$TEST$$$

^^^TEST^^^
3 3
1 2 a
2 3 a
1 3 a
----
1
$$$TEST$$$

^^^TEST^^^
8 8
1 2 a
2 3 b
1 3 c
3 4 b
4 5 a
5 6 c
6 7 b
7 8 a
-----
10
$$$TEST$$$

^^^TEST^^^
4 5
1 1 a
1 2 a
2 3 a
3 4 b
4 4 a
----
5
$$$TEST$$$

^^^TEST^^^
3 4
1 1 a
1 2 a
2 3 b
3 3 b
---
-1
$$$TEST$$$

^^^TEST^^^
9 9
1 2 a
2 3 a
3 1 a
3 4 b
4 5 a
5 6 a
6 7 a
7 8 a
9 8 a
---
11
$$$TEST$$$

^^^TEST^^^
2 1
1 2 a
---
1
$$$TEST$$$
*/

