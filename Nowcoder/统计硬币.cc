#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 111;

int dp[SIZE][SIZE];

int solve(int n, int m) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    
    const int coins[] = {1, 2, 5};
    for (int i = 0; i < 3; i++) {
        int coin = coins[i];
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                dp[j + 1][k + coin] += dp[j][k];
            }
        }
    }
    return dp[n][m];
}

int main() {
    int T;
    input(T);
    while (T--) {
        int n, m;
        input(n >> m);
        print(solve(n, m));
    }
    return 0;
}
