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

const int SIZE = 55;

llint board[SIZE + 2][SIZE + 2];
llint dp[SIZE + 2][SIZE + 2][SIZE + 2];

int main() {
    int n, m;
    input(n, m);

    memset(board, 0, sizeof(board));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%lld", &board[j][i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            board[j][i] += board[j][i - 1];
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j1 = 1; j1 <= n; j1++)
        for (int j2 = j1; j2 <= n; j2++) {
            for (int k1 = j1; k1 <= n; k1++)
            for (int k2 = max(k1, j2); k2 <= n; k2++) {
                llint delta = 0;
                if (j2 <= k1) {
                    delta = board[i][k2] - board[i][j1 - 1];
                } else {
                    delta = board[i][k1] - board[i][j1 - 1] + board[i][k2] - board[i][j2 - 1];
                }
                dp[i][k1][k2] = max(dp[i][k1][k2], dp[i - 1][j1][j2] + delta);
            }
        }
    }

    print(dp[m][n][n]);

    return 0;
}

/*
^^^^TEST^^^^
3 3
0 3 9
2 8 5
5 7 0
----
34
$$$TEST$$$

^^^^TEST^^^^
8 6
0 94 11 25 24 51 
15 13 39 67 97 19 
76 12 33 99 18 92 
35 74 0 95 71 39 
33 39 32 37 45 57 
71 95 5 71 24 86 
8 51 54 74 24 75 
70 33 63 29 99 0 
----
1382
$$$TEST$$$

*/
