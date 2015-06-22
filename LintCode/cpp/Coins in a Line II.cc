class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int n = values.size();
        
        if (n == 1) {
            return values[0] > 0;
        }
        
        vector<int> dp;
        dp.resize(n);
        
        dp[n - 1] = values[n - 1];
        dp[n - 2] = max(
            values[n - 1] + values[n - 2],
            values[n - 1] - values[n - 2]);
        for (int i = n - 3; i >= 0; i--) {
            dp[i] = max(
                values[i] + values[i + 1] - dp[i + 2],
                values[i] - dp[i + 1]);
        }
        return dp[0] > 0;
    }
};
