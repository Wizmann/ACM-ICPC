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

const int SIZE = 9;

llint board[SIZE + 2][SIZE + 2];
llint dp[SIZE + 2][SIZE + 2][SIZE + 2];

int main() {
    int n;
    input(n);

    memset(board, 0, sizeof(board));

    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) != EOF) {
        if (a + b + c == 0) {
            break;
        }
        board[a][b] = c;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            board[i][j] += board[i][j - 1];
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j1 = 1; j1 <= n; j1++)
        for (int j2 = j1; j2 <= n; j2++) {
            for (int k1 = j1; k1 <= n; k1++)
            for (int k2 = max(k1, j2); k2 <= n; k2++) {
                int delta = 0;
                if (j2 <= k1) {
                    delta = board[i][k2] - board[i][j1 - 1];
                } else {
                    delta = board[i][k1] - board[i][j1 - 1] + board[i][k2] - board[i][j2 - 1];
                }
                dp[i][k1][k2] = max(dp[i][k1][k2], dp[i - 1][j1][j2] + delta);
            }
        }
    }

    print(dp[n][n][n]);

    return 0;
}

/*
^^^^TEST^^^^
9
1 1 99
2 1 100
1 2 1
2 2 2
9 1 1000
0 0  0
----
1202
$$$TEST$$$

^^^^TEST^^^^
9
1 9 1000
2 8 1000
7 7 100
0 0  0
----
2000
$$$TEST$$$

^^^^TEST^^^^
9
1 1 99
2 1 100
1 2 1
2 2 2
1 9 1000
2 8 1000
7 7 100
0 0  0
----
2202
$$$TEST$$$


^^^TEST^^^
8
2 3 13
2 6  6
3 5  7
4 4 14
5 2 21
5 6  4
6 3 15
7 2 14
0 0  0
-----
67
$$$TEST$$$

*/
