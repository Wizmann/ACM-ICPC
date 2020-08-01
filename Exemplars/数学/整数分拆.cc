// 一个大整数，可以拆分成多少种不同整数的和
// 例如n = 5
// 5 = 5
//   = 4 + 1
//   = 3 + 2
//   = 3 + 1 + 1
//   = 2 + 2 + 1
//   = 2 + 1 + 1 + 1
//   = 1 + 1 + 1 + 1 + 1

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int MOD = 1'000'000;
const int N = 1'111'111;

int dp[N];

int solve(int n) {
    int k = 1;
    int res = 0;
    int s = 1;
    while (true) {
        int a = n - k * (3 * k + 1) / 2;
        int b = n - k * (3 * k - 1) / 2;
        if (a < 0 && b < 0) {
            break;
        }

        if (a >= 0) {
            res += s * dp[a] % MOD;
        }
        if (b >= 0) {
            res += s * dp[b] % MOD;
        }
        res %= MOD;
        s *= -1;
        k++;
    }
    return dp[n] = res % MOD;
}

int main() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    int res = 0;
    for (int i = 1; i < N; i++) {
        res = solve(i);
        if (res % MOD == 0) {
            print(i << ' ' << res);
            break;
        }
    }
    return 0;
}
