class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        int lenS = S.size();
        int lenT = T.size();
        
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i <= lenS; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= lenS; i++) {
            for (int j = 1; j <= lenT; j++) {
                char ss = S[i - 1];
                char tt = T[j - 1];
                
                if (ss == tt) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                dp[i][j] += dp[i - 1][j];
            }
        }
        return dp[lenS][lenT];
    }
public:
    static const size_t SIZE = 512;
private:
    int dp[SIZE][SIZE];
};

