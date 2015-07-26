class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int> > dp;
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int m = matrix[0].size();
        if (m == 0) {
            return 0;
        }
        
        dp.resize(n);
        for (auto& _dp: dp) {
            _dp.resize(m);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] != '1') {
                    continue;
                }
                int a = i - 1 >= 0? dp[i - 1][j]: 0;
                int b = j - 1 >= 0? dp[i][j - 1]: 0;
                int c = i - 1 >= 0 && j - 1 >= 0? dp[i - 1][j - 1]: 0;
                
                dp[i][j] = min(min(a, b), c) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};
