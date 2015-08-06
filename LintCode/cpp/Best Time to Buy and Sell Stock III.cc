class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<int> dp(n, 0);
        
        int ans = 0;
        int mini = numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            int price = prices[i];
            mini = min(mini, price);
            dp[i] = price - mini;
            ans = max(ans, dp[i]);
        }
        
        int maxi = numeric_limits<int>::min();
        int max_profit = 0;
        for (int i = n - 1; i > 0; i--) {
            int price = prices[i];
            maxi = max(maxi, price);
            max_profit = max(max_profit, maxi - price);
            ans = max(ans, max_profit + dp [i - 1]);
        }
        return ans;
    }
};
