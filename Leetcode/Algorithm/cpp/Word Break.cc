class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int len = s.length();
        
        for (int i = 0; i <= len; i++) {
            if (dp[i]) {
                string tmp;
                for (int j = i + 1; j <= len; j++) {
                    tmp += s[j - 1];
                    if (dict.find(tmp) != dict.end()) {
                        dp[j] = 1;
                    }
                }
            }
        }
        return dp[len];
    }
    
    static const int SIZE = 1024;
    int dp[SIZE];
};
