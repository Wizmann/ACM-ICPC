const int SIZE = 1000;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 2;
            } else {
                dp[i][i + 1] = 1;
            }
        }
        
        for (int i = 2; i < n; i++) {
            for (int j = 0; i + j < n; j++) {
                int k = i + j;
                dp[j][k] = max(dp[j + 1][k], dp[j][k - 1]);
                dp[j][k] = max(dp[j][k], dp[j + 1][k - 1]);
                if (s[j] == s[k]) {
                    dp[j][k] = max(dp[j][k], dp[j + 1][k - 1] + 2);
                }
            }
        }
        return dp[0][n - 1];
    }
private:
    int dp[SIZE][SIZE];
};
