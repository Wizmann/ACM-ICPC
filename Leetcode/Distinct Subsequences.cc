const int SIZEA = 20000;
const int SIZEB = 100;

int dp[SIZEA][SIZEB];

class Solution {
public:
    int numDistinct(string S, string T) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= S.size(); i++) {
            for (int j = 1; j <= T.size(); j++) {
                dp[i][j] = 0;
                if (S[i-1] == T[j-1]) {
                    for (int k = 0; k < i; k++) {
                        dp[i][j] += dp[k][j-1];
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= S.size(); i++) {
            ans += dp[i][T.size()];
        }
        return ans;
    }
};
