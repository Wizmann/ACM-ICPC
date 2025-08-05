class Solution {
    static const int INF = 0x3f3f3f3f;
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        
        if (n == 0) {
            return 0;
        }
        
        if (k >= n / 2) {
            int a = -prices[0];
            int b = 0;
            for (int i = 1; i < n; i++) {
                int aa = max(a, b - prices[i]);
                int bb = max(b, a + prices[i]);
                a = aa;
                b = bb;
            }
            return max(a, b);
        }
        
        vector<int> dp[2];
        for (int i = 0; i < 2; i++) {
            dp[i].resize(n);
            fill(dp[i].begin(), dp[i].end(), 0);
        }
        
        
        int ptr = 0;
        
        for (int i = 0; i < min(n, 2 * k); i++) {
            int next = ptr ^ 1;
            fill(dp[next].begin(), dp[next].end(), -INF);
            
            for (int j = i; j < n; j++) {
                if (ptr == 0) {
                    dp[next][j] = dp[ptr][j] - prices[j];
                } else {
                    dp[next][j] = dp[ptr][j] + prices[j];
                }
                if (j - 1 >= 0) {
                    dp[next][j] = max(dp[next][j], dp[next][j - 1]);
                }
                ans = max(ans, dp[next][j]);
            }
            ptr = next;
        }
        return ans;
    }
};
