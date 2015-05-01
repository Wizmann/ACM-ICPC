class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        int ans = 0;
        if (k == 0 || n == 0) {
            return 0;
        }
        
        if (k >= n / 2) {
            for (int i = 1; i < n; i++) {
                if (prices[i - 1] < prices[i]) {
                    ans += prices[i] - prices[i - 1];
                }
            }
            return ans;
        }
        
        vector<vector<int> > dp;
        dp.resize(2);
        for (auto& subdp: dp) {
            subdp.resize(n);
        }
       
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[0][i] = -prices[0];
            } else {
                dp[0][i] = max(dp[0][i - 1], -prices[i]);
            }
        }
        
        for (int i = 1; i < 2 * k; i++) {
            int p = i % 2;
            for (int j = i; j < n; j++) {
                dp[p][j] = -INF;
                int s = i % 2? 1: -1;
                if (j == i) {
                    dp[p][j] = s * prices[j] + dp[p^1][j - 1];
                } else {
                    dp[p][j] = max(dp[p][j - 1], s * prices[j] + dp[p^1][j - 1]);
                }
                ans = max(ans, dp[p][j]);
            }
        }        
        return ans;
    }
private:
    static const int INF = 0x3f3f3f3f;
};
