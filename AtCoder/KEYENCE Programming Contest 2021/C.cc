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

const llint MOD = 998244353;

const int N = 5555;

int n, m, k;

char grid[N][N];
int dp[2][N];

int xs[N][N];
int ys[N][N];
int powpow[N];

int main() {
    input(n, m, k);

    memset(grid, 0, sizeof(grid));

    powpow[0] = 1;
    for (int i = 1; i < N; i++) {
        powpow[i] = 3LL * powpow[i - 1] % MOD;
    }

    int a, b;
    char c[10];
    for (int i = 0; i < k; i++) {
        scanf("%d%d%s", &a, &b, c);
        grid[a][b] = c[0];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            xs[i][j] += xs[i][j - 1] + (grid[i][j] == '\0'? 1: 0);
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            ys[i][j] += ys[i - 1][j] + (grid[i][j] == '\0'? 1: 0);
        }
    }

    int p = 1;
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        int q = p ^ 1;
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            llint cur = 0;
            if (i - 1 > 0) {
                llint a = 0;
                if (grid[i - 1][j] == 'D' || grid[i - 1][j] == 'X') {
                    a += dp[q][j];
                } else if (grid[i - 1][j] == '\0') {
                    a += dp[q][j] * 2;
                }
                a *= powpow[xs[i][j - 1]];
                cur += a;
            }
            if (j - 1 > 0) {
                llint b = 0;
                if (grid[i][j - 1] == 'R' || grid[i][j - 1] == 'X') {
                    b += dp[p][j - 1];
                } else if (grid[i][j - 1] == '\0') {
                    b += dp[p][j - 1] * 2;
                }
                b *= powpow[ys[i - 1][j]];
                cur += b;
            }
            dp[p][j] = cur % MOD;
        }
        /*
        for (int j = 1; j <= m; j++) {
            printf("%lld ", dp[p][j]);
        }
        puts("");
        */
        p = q;
    }

    llint res = dp[p ^ 1][m];
    if (grid[n][m] == '\0') {
        res = res * 3 % MOD;
    }
    print(res);

    return 0;
}

/*
^^^TEST^^^
2 2 3
1 1 X
2 1 R
2 2 R
---
5
$$$TEST$$$

^^^TEST^^^
3 3 5
2 3 D
1 3 D
2 1 D
1 2 X
3 1 R
-----
150
$$$TEST$$$

^^^TEST^^^
5000 5000 10
585 1323 R
2633 3788 X
1222 4989 D
1456 4841 X
2115 3191 R
2120 4450 X
4325 2864 X
222 3205 D
2134 2388 X
2262 3565 R
----
139923295
$$$TEST$$$

*/
