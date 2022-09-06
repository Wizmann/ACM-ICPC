#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int INF = 0x3f3f3f3f;
const int SIZE = 44;

int n, m;
int matrix[SIZE][SIZE];
int dp[SIZE][SIZE][SIZE][SIZE];

int solve(int y1, int x1, int y2, int x2) {
    if (dp[y1][x1][y2][x2] != -1) {
        return dp[y1][x1][y2][x2];
    }

    if (y1 == y2 && x1 == x2) {
        return 0;
    }

    int mini = INF;
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            mini = min(mini, matrix[i][j]);
        }
    }

    int res = -1;
    for (int i = y1; i + 1 <= y2; i++) {
        res = max(res, 
                solve(y1, x1, i, x2) + solve(i + 1, x1, y2, x2));
    }

    for (int i = x1; i + 1 <= x2; i++) {
        res = max(res, 
                solve(y1, x1, y2, i) + solve(y1, i + 1, y2, x2));
    }

    return dp[y1][x1][y2][x2] = res + mini;
}

int main() {
    int T;
    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        printf("Case #%d: ", case_ + 1);

        input(n >> m);

        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                input(matrix[i][j]);
            }
        }

        print(solve(0, 0, n - 1, m - 1));
    }

    return 0;
}
