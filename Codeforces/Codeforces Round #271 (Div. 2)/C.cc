#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const int SIZE = 123456;
const int MOD = 1000000007;

llint dp[SIZE];
int q, k;

void init()
{
    for (int i = 0; i < k; i++) {
        dp[i] = 1;
    }
    for (int i = k; i < SIZE; i++) {
        dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
    }
    for (int i = 1; i< SIZE; i++) {
        dp[i] += dp[i - 1];
        dp[i] %= MOD;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b;
    input(q >> k);
    init();
    while (q--) {
        input(a >> b);
        print((dp[b] - dp[a - 1] + MOD) % MOD);
    }
    return 0;
}
