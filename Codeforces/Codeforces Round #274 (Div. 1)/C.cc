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

const int SIZE = 5555;
const int MOD = 1000000007;

int n, a, b, k;
llint dp[2][SIZE];
llint s[SIZE];

int main()
{
    freopen("input.txt", "r", stdin);
    input(n >> a >> b >> k);
    int ptr = 0;
    dp[0][a] = 1;
    for (int i = 0; i < k; i++) {
        int next = ptr ^ 1;
        memset(dp[next], 0, sizeof(dp[next]));
        for (int j = 1; j <= n; j++) {
            s[j] = s[j - 1] + dp[ptr][j];
            s[j] %= MOD;
        }
        for (int j = 1; j <= n; j++) {
            int delta = abs(j - b) - 1;
            if (j < b) {
                dp[next][j] += s[j - 1];
                dp[next][j] %= MOD;
                dp[next][j] += s[b - (delta + 1) / 2 - 1] - s[j];
                dp[next][j] %= MOD;
            }
            if (j > b) {
                dp[next][j] += s[n] - s[j];
                dp[next][j] %= MOD;
                dp[next][j] += s[j - 1] - s[j - delta / 2 - 1];
                dp[next][j] %= MOD;
            }
        }
        ptr = next;
    }
    llint sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += dp[ptr][i];
        sum %= MOD;
    }
    print((sum + MOD) % MOD);
    return 0;
}
