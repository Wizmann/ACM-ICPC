class Solution {
public:
    int numSquares(int n) {
        vector<int> dp = {0, 1, 2};
        for(int i = 3; i <= n; i++) {
            int mini = numeric_limits<int>::max();
            for (int j = 1; j * j <= i; j++) {
                mini = min(mini, dp[i - j * j] + 1);
            }
            dp.push_back(mini);
        }
        return dp[n];
    }
};
