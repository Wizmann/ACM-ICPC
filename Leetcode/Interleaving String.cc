const int SIZE = 1024;
char dp[SIZE][SIZE];
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s3[i]) {
                dp[i+1][0] = 1;
            } else {
                break;
            }
        }
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] == s3[i]) {
                dp[0][i+1] = 1;
            } else {
                break;
            }
        }
        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                dp[i+1][j+1] = (dp[i][j+1] && s1[i] == s3[i+j+1]) ||
                               (dp[i+1][j] && s2[j] == s3[i+j+1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
