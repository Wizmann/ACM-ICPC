#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int MOD = 1000000000 + 7;

typedef long long llint;

int n;
vector<llint> dp[2];

int init(int n) {
    int maxi = n * 9 + 1;
    
    dp[0] = vector<llint>(maxi, 0);
    dp[1] = vector<llint>(maxi, 0);
    
    int ptr = 0;
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        int next = ptr ^ 1;
        dp[next] = vector<llint>(maxi, 0);
        for (int j = n * 9; j >= 0; j--) {
            if (dp[ptr][j]) {
                for (int k = 0; k <= 9; k++) {
                    if (j + k < maxi) {
                        dp[next][j + k] += dp[ptr][j];
                        dp[next][j + k] %= MOD;
                    }
                }
            }
        }
        ptr = next;
    }
    return ptr;
}

int main() {
    input(n);
    int ptr = init(n);
    llint ans = 0;
    
    for (int i = 0; i <= n * 9; i++) {
        ans += (dp[ptr][i] * dp[ptr][i]) % MOD;
        ans -= (dp[ptr ^ 1][i] * dp[ptr][i]) % MOD;
        ans = ((ans % MOD) + MOD) % MOD;
    }
    print(ans);
    return 0;
}
