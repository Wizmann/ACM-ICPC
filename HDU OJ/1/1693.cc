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

const int N = 11;
int board[N + 12][N + 12];
llint dp[2][1 << (N + 1)];

llint solve(int n, int m) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int p = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int q = p ^ 1;
            memset(dp[q], 0, sizeof(dp[q]));
            for (int k = 0; k < 1 << (m + 1); k++) {
                if (dp[p][k] == 0) {
                    continue;
                }
                int nxt_base = (k << 1) & ((1 << (m + 1)) - 4);
                assert((nxt_base & 3) == 0);
                bool down = k & (1 << m);
                bool right = k & 1;
                if (board[i][j] == 0) {
                    if (down || right) {
                        continue;
                    }
                    int nxt = nxt_base;
                    dp[q][nxt] += dp[p][k];
                } else {
                    // "-"
                    if (!down && right && j + 1 < m && j - 1 >= 0) {
                        int nxt = nxt_base | 1;
                        dp[q][nxt] += dp[p][k];
                    }
                    // "|"
                    if (down && !right && i + 1 < n && i - 1 >= 0) {
                        int nxt = nxt_base | 2;
                        dp[q][nxt] += dp[p][k];
                    }
                    // ┘
                    if (i - 1 >= 0 && j - 1 >= 0 && down && right) {
                        int nxt = nxt_base;
                        dp[q][nxt] += dp[p][k];
                    }
                    // └
                    if (i - 1 >= 0 && j + 1 < m && down && !right) {
                        int nxt = nxt_base | 1;
                        dp[q][nxt] += dp[p][k];
                    }
                    // ┌
                    if (j + 1 < m && i + 1 < n && !down && !right) {
                        int nxt = nxt_base | 3;
                        dp[q][nxt] += dp[p][k];
                    }
                    // ┐
                    if (j - 1 >= 0 && i + 1 < n && !down && right) {
                        int nxt = nxt_base | 2;
                        dp[q][nxt] += dp[p][k];
                    }
                }
            }
            p = q;
        }
    }
    return dp[p][0];
}

int main() {
    int T;
    input(T);

    int n, m;
    for (int case_ = 0; case_ < T; case_++) {
        input(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &board[i][j]);
            }
        }
        llint res = solve(n, m);

        printf("Case %d: There are %lld ways to eat the trees.\n",
            case_ + 1, res);
    }

    return 0;
}

/*

^^^TEST^^^
1
2 2
1 1
1 1
---
Case 1: There are 1 ways to eat the trees.
$$$TEST$$$

^^^TEST^^^
2
6 3
1 1 1
1 0 1
1 1 1
1 1 1
1 0 1
1 1 1
2 4
1 1 1 1
1 1 1 1
-----
Case 1: There are 3 ways to eat the trees.
Case 2: There are 2 ways to eat the trees.
$$$TEST$$$

*/
