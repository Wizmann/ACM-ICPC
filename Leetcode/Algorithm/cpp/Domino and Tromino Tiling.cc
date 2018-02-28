typedef long long llint;

const int SIZE = 1111;
const int MOD = 1000000000 + 7;

class Solution {
public:
    int numTilings(int N) {
        memset(dp, 0, sizeof(dp));
        dp[3][0] = 1;
        
        for (int i = 0; i < N; i++) {
            dp[2][i + 1] = (dp[2][i + 1] + dp[1][i]) % MOD;
            dp[3][i + 1] = (dp[3][i + 1] + dp[1][i]) % MOD;
            dp[3][i + 1] = (dp[3][i + 1] + dp[2][i]) % MOD;
            dp[1][i + 1] = (dp[1][i + 1] + dp[2][i]) % MOD;
            dp[3][i + 1] = (dp[3][i + 1] + dp[3][i]) % MOD;
            dp[3][i + 2] = (dp[3][i + 2] + dp[3][i]) % MOD;
            dp[1][i + 2] = (dp[1][i + 2] + dp[3][i]) % MOD;
            dp[2][i + 2] = (dp[2][i + 2] + dp[3][i]) % MOD;
        }
        
        return dp[3][N];
    }
private:
    llint dp[4][SIZE];
};
