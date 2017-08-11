#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1111;
const int INF = 0x3f3f3f3f;

int dp[SIZE][SIZE];

int dfs(int n, int k) {
    if (dp[n][k] != INF) {
        return dp[n][k];
    }

    if (k == 0) {
        return 0;
    }
    
    if (n == 0) {
        return INF;
    }

    int ans = INF;
    for (int i = 1; i <= k; i++) {
        ans = min(ans, 
                max(dfs(n - 1, i - 1), dfs(n, k - i)) + 1);
    }
    return dp[n][k] = ans;
}

int solve(int n, int k) {
    memset(dp, INF, sizeof(dp));
    return dfs(n, k);
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, k;
    while (input(n >> k)) {
        print(solve(n, k));
    }
    return 0;
}
