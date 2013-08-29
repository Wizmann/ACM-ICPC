const int SIZE = 1024;
int dp[SIZE];

class Solution {
public:
    int climbStairs(int n) {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (i - 2 >= 0) {
                dp[i] += dp[i - 2];
            }
            if (i - 1 >= 0) {
                dp[i] += dp[i - 1];
            }
        }
        return dp[n];
    }
};
