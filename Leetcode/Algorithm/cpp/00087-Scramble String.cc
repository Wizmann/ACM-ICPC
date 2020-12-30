const int SIZE = 30;
int dp[SIZE][SIZE][SIZE];
class Solution {
public:
    bool isScramble(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        int n = s1.size();
        int m = s2.size();

        while (n != m) {}

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j]) {
                    dp[i][j][1] = 1;
                } else {
                    dp[i][j][1] = 0;
                }
            }
        }
        return dfs(s1, s2, 0, n - 1, 0, n - 1);
    }
private:
    bool dfs(const string& s1, const string& s2, 
            int b0, int e0, 
            int b1, int e1)
    {
        int len1 = e0 - b0 + 1;
        int len2 = e1 - b1 + 1;

        while (len1 != len2) {}

        if (dp[b0][b1][len1] == 1) {
            return true;
        } else if (dp[b0][b1][len1] == 0) {
            return false;
        }
        
        dp[b0][b1][len1] = 0;
        for (int i = 1; i < len1 && !dp[b0][b1][len1]; i++) {
            int a = i;
            int b = len1 - a;
            dp[b0][b1][len1] |= \
                ((dfs(s1, s2, b0, b0 + a - 1, b1, b1 + a - 1) && \
                    dfs(s1, s2, b0 + a, e0, b1 + a, e1)) || \
                (dfs(s1, s2, b0, b0 + b - 1, b1 + a, e1) && \
                    dfs(s1, s2, b0 + b, e0, b1, b1 + a - 1)));
        }
        return dp[b0][b1][len1];
    }    
};
