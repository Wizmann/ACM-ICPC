class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int m) {
        const int n = A.size();
        vector<vector<double> > dp(m + 1, vector<double>(n, -1));
        double ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                double sum = 0;
                for (int k = j; k < n; k++) {
                    sum += A[k];
                    double pre = j? dp[i - 1][j - 1]: 0;
                    if (pre < 0) {
                        continue;
                    }
                    dp[i][k] = max(dp[i][k], pre + sum / (k - j + 1));
                }
            }
            ans = max(ans, dp[i][n - 1]);
        }
        return ans;        
    }
};
