const int N = 5555;
const int MAXI = 15;
const int DICE = 6;
const int MOD = 1000000000 + 7;

int dp[N][MAXI + 2][DICE + 2];

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= MAXI; j++) {
                for (int k1 = 0; k1 <= DICE; k1++) {
                    if (dp[i][j][k1] == 0) {
                        continue;
                    }
                    for (int k2 = 1; k2 <= DICE; k2++) {
                        if (k1 == k2) {
                            if (rollMax[k1 - 1] < j + 1) {
                                continue;
                            } else {
                                dp[i + 1][j + 1][k1] += dp[i][j][k1];
                                dp[i + 1][j + 1][k1] %= MOD;
                            }
                        } else {
                            dp[i + 1][1][k2] += dp[i][j][k1];
                            dp[i + 1][1][k2] %= MOD;
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= DICE; i++) {
            for (int j = 1; j <= MAXI; j++) {
                res = (res + dp[n][j][i]) % MOD;
            }
        }
        return res;
    }
};
