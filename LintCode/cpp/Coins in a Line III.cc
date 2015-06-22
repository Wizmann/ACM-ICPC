class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int n = values.size();
        dp.resize(n);
        for (auto& _dp: dp) {
            _dp.resize(n);
        }
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = values[i];
        }
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j + i <= n; j++) {
                int a = j;
                int b = j + i - 1;
                
                dp[a][b] = max(
                    values[a] - dp[a + 1][b],
                    values[b] - dp[a][b - 1]
                );
            }
        }
        return dp[0][n - 1] > 0;
    }
private:
    vector<vector<int> > dp;
};
