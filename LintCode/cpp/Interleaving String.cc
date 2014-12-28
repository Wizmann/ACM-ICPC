class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        
        if (l3 != l1 + l2) {
            return false;
        }
        if (l1 == 0) {
            return s2 == s3;
        }
        if (l2 == 0) {
            return s1 == s3;
        }
        
        for (int i = 0; i <= l1; i++) {
            for (int j = 0; j <= l2; j++) {
                int k = i + j;
                if (i < l1 && s1[i] == s3[k]) {
                    dp[i + 1][j] |= dp[i][j];
                }
                if (j < l2 && s2[j] == s3[k]) {
                    dp[i][j + 1] |= dp[i][j];
                }
            }
        }
        return dp[l1][l2];
    }
private:
    static const int SIZE = 1024;
    char dp[SIZE][SIZE];
};
