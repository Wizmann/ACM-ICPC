#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 111;

int n, m, u;
char board[SIZE][SIZE];
int dp[SIZE][SIZE];
int height[SIZE][SIZE];
int dp1[SIZE][SIZE][SIZE];

int sum_range(int a, int b, int c) {
    return (1LL * a + b) * ((b - a) / c + 1) / 2;
}

int solve1() {
    int maxi = 0;
    memset(height, 0, sizeof(height));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '#') {
                maxi = max(maxi, 1);
                int p = j;
                int l = 1;
                int h = 1;
                for (int k = i + 1; k < n; k++) {
                    p--;
                    l += 2;
                    if (p >= 0 && p + l - 1 < m) {
                        int t = dp[k][p + l - 1] - (p - 1 >= 0? dp[k][p - 1]: 0);
                        if (t == l) {
                            maxi = max(maxi, sum_range(1, l, 2));
                            h++;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }
                height[i][j] = h;
            }
        }
    }
    return maxi;
}

int solve2() {
    memset(dp1, 0, sizeof(dp1));
    for (int k = 0; k < u; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int pre = 0;
                if (k > 0) {
                    if (i == 0 || dp1[k - 1][i - 1][j] == 0) {
                        continue;
                    }
                    pre = dp1[k - 1][i - 1][j];
                }

                if (k && pre == 0) {
                    continue;
                }

                for (int h = 1; h <= height[i][j]; h++) {
                    int y = i + h - 1;
                    int x1 = j - h + 1;
                    int x2 = j + h - 1;
                    if (y > n) {
                        break;
                    }
                    if (x1 < 0 || x2 > m) {
                        break;
                    }
                    for (int x = x1; x <= x2; x++) {
                        dp1[k][y][x] = max(dp1[k][y][x], pre + h * h);
                    }
                }
            }
        }
    }
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // printf("%d ", dp1[u - 1][i][j]);
            maxi = max(maxi, dp1[u - 1][i][j]);
        }
        // puts("");
    }
    return maxi;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int T;
    input(T);
    for (int case_ = 0; case_ < T; case_++) {
        input(n >> m >> u);
        memset(board, 0, sizeof(board));
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < n; i++) {
            input(board[i]);
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') {
                    dp[i][j] = 1;
                }
                dp[i][j] += j - 1 >= 0? dp[i][j - 1]: 0;
            }
        }
        solve1();
        printf("Case #%d: %d\n", case_ + 1, solve2());
    }
    return 0;
}
