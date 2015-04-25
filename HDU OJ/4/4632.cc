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
const int MOD = 10007;

int n;
int dp[SIZE][SIZE];
string word;

int do_mod(int value) {
    return ((value % MOD) + MOD) % MOD;
}

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
                dp[l][r] = do_mod(
                    dp[l][r - 1] + dp[l + 1][r] + 1);
            } else {
                dp[l][r] = do_mod(
                    dp[l][r - 1] + dp[l + 1][r] - dp[l + 1][r - 1]);
            }
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
        printf("Case %d: %d\n", cas++, solve() % MOD);
    }
    return 0;
}
