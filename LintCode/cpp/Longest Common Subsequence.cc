class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        int la = A.size();
        int lb = B.size();
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        
        for (int i = 1; i <= la; i++) {
            for (int j = 1; j <= lb; j++) {
                int ca = A[i - 1];
                int cb = B[j - 1];
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (ca == cb) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
private:
    static const int SIZE = 1024;
    int dp[SIZE][SIZE];
};

