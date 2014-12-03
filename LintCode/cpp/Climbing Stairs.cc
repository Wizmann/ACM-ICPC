class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        dp.resize(n + 1);
        dp[0] = 1;
        for (int i = 0; i <= n; i++) {
            if (i - 1 >= 0) {
                dp[i] += dp[i - 1];
            }
            if (i - 2 >= 0) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
private:
    vector<int> dp;
};

