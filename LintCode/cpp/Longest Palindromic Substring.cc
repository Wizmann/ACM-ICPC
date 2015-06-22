const int SIZE = 1024;

class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        int n = s.size();
        if (n == 0) {
            return "";
        }
        
        int idx = 0;
        int len = 1;
        
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (i + 1 < n && s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                idx = i;
                len = 2;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; i + j < n; j++) {
                int a = j;
                int b = j + i;
                
                if (s[a] != s[b]) {
                    continue;
                }
                
                if (dp[a + 1][b - 1]) {
                    dp[a][b] = 1;
                    if (b - a + 1 > len) {
                        idx = a;
                        len = b - a + 1;
                    }
                }
            }
        }
        return s.substr(idx, len);
    }
private:
    int dp[SIZE][SIZE];
};
