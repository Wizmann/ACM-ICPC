class Solution {
public:
    static const int SIZE = 10240;
    int dp[SIZE];
    int numDecodings(string s) {
        memset(dp, 0 ,sizeof(dp));
        int sz = s.length();
        if (sz == 0 || s[0] == '0') {
            return 0;
        }

        if (sz == 1) {
            return 1;
        }
                
        dp[0] = 1;
        dp[1] = bool(is_valid(s[0], s[1])) + bool(s[1] != '0');
        
        for (int i = 2; i < sz; i++) {
            if (s[i] != '0') {
                dp[i] += dp[i-1];
            }
            if (is_valid(s[i-1], s[i])) {
                dp[i] += dp[i-2];
            }
        }
        return dp[sz-1];
    }
    
    bool is_valid(char a, char b) {
        if (a == '0') {
            return false;
        }
        int x = (a - '0') * 10 + b - '0';
        if (x >= 1 && x <= 26) {
            return true;
        } else {
            return false;
        }
    }
};
