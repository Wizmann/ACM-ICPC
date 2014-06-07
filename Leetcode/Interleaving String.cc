class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int> > dp;
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        
        dp.resize(l1 + 5);
        for (int i = 0; i < (int)dp.size(); i++) {
            dp[i].resize(l2 + 5);
            fill(dp[i].begin(), dp[i].end(), -1);
        }
        
        dp[0][0] = 0;
        for (int i = 0; i <= l1; i++) {
            for (int j = 0; j <= l2; j++) {
                if (i - 1 >= 0 && dp[i - 1][j] != -1) {
                    int p3 = dp[i - 1][j];
                    if (s1[i - 1] == s3[p3]) {
                        dp[i][j] = p3 + 1;
                    }
                }
                
                if (j - 1 >= 0 && dp[i][j - 1] != -1) {
                    int p3 = dp[i][j - 1];
                    if (s2[j - 1] == s3[p3]) {
                        dp[i][j] = p3 + 1;
                    }
                }
            }
        }
        
        return dp[l1][l2] == l3;
    }
};
