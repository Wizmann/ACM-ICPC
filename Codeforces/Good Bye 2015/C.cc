#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 555;

char board[SIZE][SIZE];
int dp0[SIZE][SIZE];
int dp1[SIZE][SIZE];
int n, m, q;

void init(int dp[SIZE][SIZE], int my, int mx) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != '.') {
                continue;
            }
            int ny = i + my;
            int nx = j + mx;
            if (board[ny][nx] != '.') {
                continue;
            }

            dp[i][j]++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - 1 >= 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j - 1 >= 0) {
                dp[i][j] += dp[i][j - 1];
            }
            if (i - 1 >= 0 && j - 1 >= 0) {
                dp[i][j] -= dp[i - 1][j - 1];
            }
        }
    }
}

int do_solve(int dp[SIZE][SIZE], int y1, int x1, int y2, int x2) {
    if (x2 < x1) {
        return 0;
    }
    int res = 0;
    res += dp[y2][x2];
    res -= y1 - 1 >= 0? dp[y1 - 1][x2]: 0;
    res -= x1 - 1 >= 0? dp[y2][x1 - 1]: 0;
    res += x1 - 1 >= 0 && y1 - 1 >= 0? dp[y1 - 1][x1 - 1]: 0;
    return res;
}

int solve(int y1, int x1, int y2, int x2) {
    int a = do_solve(dp0, y1, x1, y2, x2 - 1);
    int b = do_solve(dp1, y1, x1, y2 - 1, x2);
    // print(a << ' ' << b);
    return a + b;
}

int main() {
    input(n >> m);
    
    memset(dp0, 0, sizeof(dp0));
    memset(dp1, 0, sizeof(dp1));
    
    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
    }

    init(dp0, 0, 1); // 横着的
    init(dp1, 1, 0); // 竖着的

    input(q);
    int a, b, c, d;
    while (q--) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        a--; b--; c--; d--;
        printf("%d\n", solve(a, b, c, d));
    }

    return 0;
}
