class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> dp[2];
        int n = prices.size();
        if (!n) {
            return 0;
        }
        dp[0].resize(n);
        dp[1].resize(n);
        
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]);
        }
        return dp[0][n - 1];
    }
};
