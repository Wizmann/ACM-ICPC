#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 2222;
const int MOD = 1'000'000'000 + 7;

int n, h;
llint dp[SIZE][SIZE];
vector<int> ns;

llint solve() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 0; i + 1 <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i][j] == 0) {
                continue;
            }
            int diff = h - ns[i + 1];

            if (diff < 0) {
                // pass
            } else if (diff == 0) {
                dp[i + 1][0] += dp[i][j];
                dp[i + 1][0] %= MOD;
            } else if (diff == j) {
                dp[i + 1][diff] += dp[i][j] * (j + 1) % MOD;
                dp[i + 1][diff] %= MOD;
            } else if (diff == j - 1) {
                dp[i + 1][diff] += dp[i][j] * j % MOD;
                dp[i + 1][diff] %= MOD;
            } else if (diff == j + 1) {
                dp[i + 1][diff] += dp[i][j];
                dp[i + 1][diff] %= MOD;
            }
        }
    }
    /*
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%lld ", dp[i][j]);
        }
        puts("");
    }
    puts("");
    */
    return (dp[n][0] + dp[n][1]) % MOD;
}

int main() {
    input(n >> h);
    ns = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ns[i]);
    }

    print(solve());

    return 0;
}
