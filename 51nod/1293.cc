#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 1111;
const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

struct Node {
    llint down;
    llint right;
};

int m, n, k;
int board[SIZE][SIZE];
Node dp[SIZE][SIZE]; 

int main() {
    freopen("input.txt", "r", stdin);
    input(m >> n >> k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    dp[0][0] = {k, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur = board[i][j];
            llint down = dp[i][j].down;
            llint right = dp[i][j].right;

            if (cur == 0) {
                if (i + 1 <= n) {
                    dp[i + 1][j].down += down;
                }
                if (j + 1 <= m) {
                    dp[i][j + 1].right += right;
                }
            } else if (cur == +1) {
                llint tot = down + right;
                if (i + 1 <= n) {
                    dp[i + 1][j].down += tot / 2;
                }
                if (j + 1 <= m) {
                    dp[i][j + 1].right += (tot + 1) / 2;
                }
            } else if (cur == -1) {
                llint tot = down + right;
                if (i + 1 <= n) {
                    dp[i + 1][j].down += (tot + 1)/ 2;
                }
                if (j + 1 <= m) {
                    dp[i][j + 1].right += tot / 2;
                }
            }
        }
    }
    print(dp[n][m - 1].down);

    return 0;
}
