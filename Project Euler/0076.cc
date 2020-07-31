#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 111;

int dp[N][N];

int solve(int n, int m) {
    if (dp[n][m] != -1) {
        return dp[n][m];
    }
    if (n == 0) {
        return 1;
    }
    if (m == 0) {
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= min(m, n); i++) {
        cnt += solve(n - i, i);
    }
    print(n << ' ' << m << ' ' << cnt);
    return dp[n][m] = cnt;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n = 100;
    int res = solve(n, n - 1);
    print(res);
    return 0;
}

