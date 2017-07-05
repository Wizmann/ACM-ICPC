const int SIZE = 1200;
const int MOD = 1000000000 + 7;

int dp[2][SIZE];

class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k == 0) {
            return 1;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < SIZE; i++) {
            dp[1][i] = 1;
        }
        int p, q;
        for (int i = 1; i < n; i++) {
            p = i % 2;
            q = p ^ 1;
            memset(dp[q], 0, sizeof(dp[q]));
            
            for (int j = 0; j < SIZE; j++) {
                if (j) {
                    dp[q][j] += dp[q][j - 1];
                }
                dp[q][j] = (dp[q][j] % MOD + MOD) % MOD;
                dp[q][j] += dp[p][j] - (j - i - 1 >= 0? dp[p][j - i - 1]: 0);
                dp[q][j] = (dp[q][j] % MOD + MOD) % MOD;
                //printf("%d ", dp[q][j]);
            }
            //puts("");
        }

        int ans = dp[q][k] - dp[q][k - 1];
        return (ans % MOD + MOD) % MOD;
    }
};
