#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 555;
const int INF = 0x3f3f3f3f;

int n, m;
int dp[SIZE][SIZE];
int maze[SIZE][SIZE];

int solve() {
    memset(dp, INF, sizeof(dp));
    dp[n - 1][m - 1] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int u = maze[i][j];
            int a = INF;
            int b = INF;
            if (j + 1 < m) {
                a = max(0, dp[i][j + 1] - u);
            }
            if (i + 1 < n) {
                b = max(0, dp[i + 1][j] - u);
            }
            dp[i][j] = min(
                    dp[i][j],
                    min(a, b));
        }
    }
    return dp[0][0];
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    input(T);
    while (T--) {
        input(n >> m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &maze[i][j]);
            }
        }
        print(solve() + 1);
    }
    return 0;
}
