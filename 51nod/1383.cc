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

const int SIZE = 1111111;
const int MOD = 1000000007;

int n;
vector<llint> dp;

int main() {
    freopen("input.txt", "r", stdin);
    input(n);
    dp.resize(SIZE);

    dp[0] = 1;
   
    for (llint i = 1; i <= n; i <<= 1) {
        for (int j = 0; j <= n; j++) {
            if (dp[j] && j + i <= n) {
                dp[j + i] = (dp[j + i] + dp[j]) % MOD;
            }
        }
    }

    print(dp[n]);
    return 0;
}

