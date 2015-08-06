class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        prices.push_back(-1);
        
        int ans = 0;
        
        int n = prices.size();
        
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] < prices[i]) {
                ans += prices[i] - prices[i - 1];
            }
        }
        return ans;
    }
};
