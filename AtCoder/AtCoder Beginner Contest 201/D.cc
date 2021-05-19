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

const int N = 2222;

char board[N][N];
int dp[N][N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '+') {
                board[i][j] = 1;
            } else if (board[i][j] == '-') {
                board[i][j] = -1;
            } else {
                assert (false);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -INF;
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            bool flag = false;
            int cur = -INF;

            if (j + 1 < m) {
                cur = max(cur, board[i][j + 1] - dp[i][j + 1]);
                flag = true;
            }

            if (i + 1 < n) {
                cur = max(cur, board[i + 1][j] - dp[i + 1][j]);
                flag = true;
            }

            if (flag == false) {
                cur = 0;
            }

            dp[i][j] = max(dp[i][j], cur);
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", dp[i][j]);
        }
        puts("");
    }
    */

    if (dp[0][0] > 0) {
        puts("Takahashi");
    } else if (dp[0][0] < 0) {
        puts("Aoki");
    } else {
        puts("Draw");
    }

    return 0;
}

/*

^^^TEST^^^
3 3
---
+-+
+--
-----
Takahashi
$$$TEST$$$

^^^TEST^^^
2 4
+++-
-+-+
-----
Aoki
$$$TEST$$$

^^^TEST^^^
1 1
-
------
Draw
$$$TEST$$$


*/
