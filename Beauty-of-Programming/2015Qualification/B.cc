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

const int SIZE = 1234;
const int MOD = 100007;

int n;
int dp[SIZE][SIZE];
string word;

int solve() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; i + j < n; j++) {
            int l = j;
            int r = i + j;
            if (word[l] == word[r]) {
                int a = dp[l][r - 1];
                int b = dp[l + 1][r];
                
                dp[l][r] = (a + b + 1) % MOD;
            }
            dp[l][r] = max(dp[l][r], 
                dp[l][r - 1] + dp[l + 1][r] - dp[l + 1][r - 1]) % MOD;
        }
    }
    return dp[0][n - 1];
}

int main() {
    int T, cas = 1;
    input(T);
    while (T--) {
        input(word);
        n = word.size();
        printf("Case #%d: %d\n", cas++, solve() % MOD);
    }
    return 0;
}
