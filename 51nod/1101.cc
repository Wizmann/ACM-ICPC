#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 123456;
const int MOD = 1000000000 + 7;

int n;
int dp[SIZE];
vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

int main() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    input(n);
    for (auto coin: coins) {
        for (int i = 0; i <= n; i++) {
            if (dp[i] != 0 && i + coin <= n) {
                dp[i + coin] += dp[i];
                dp[i + coin] %= MOD;
            }
        }
    }
    print(dp[n]);
    return 0;
}
