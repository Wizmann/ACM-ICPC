const int INF = 0x3f3f3f3f;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        
        for (auto coin: coins) {
            for (int i = 1; i * coin <= amount; i <<= 1) {
                for (int j = amount; j >= 0; j--) {
                    if (dp[j] == INF || j + i * coin > amount) {
                        continue;
                    }
                    dp[j + i * coin] = min(dp[j + i * coin], dp[j] + i);
                }
            }
        }
        return dp[amount] == INF? -1: dp[amount];
    }
};
