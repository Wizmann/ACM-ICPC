const int SIZE = 555;
const int INF = 0x3f3f3f3f;

int dp[SIZE][SIZE];

class Solution {
public:
    int minDistance(string word1, string word2) {
        memset(dp, INF, sizeof(dp));
        n = word1.size();
        m = word2.size();
        
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; i++) {
            dp[i][0] = i;
        }
        
        for (int i = 1; i <= m; i++) {
            dp[0][i] = i;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char c1 = word1[i - 1];
                char c2 = word2[j - 1];
                
                if (c1 == c2) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 2);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
        return dp[n][m];
    }
private:
    int n, m;
};
