class Solution {
public:
    static const int SIZE = 512;
    int dp[SIZE][SIZE];
    
    int minDistance(string word1, string word2) {
        memset(dp, 0 ,sizeof(dp));
        int len1 = word1.size();
        int len2 = word2.size();
        
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = i;
        }
        
        for (int j = 0; j <= len2; j++) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                dp[i][j] = min(
                    min(
                        dp[i-1][j] + 1, 
                        dp[i][j-1] + 1
                    ),
                    dp[i-1][j-1] + (word1[i-1] == word2[j-1]? 0 : 1)
                );
            }
        }
        return dp[len1][len2];
    }
};
