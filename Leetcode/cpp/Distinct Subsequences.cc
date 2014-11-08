class Solution {
public:
    int numDistinct(string S, string T) {
        int ls = S.size();
        int lt = T.size();
        vector<vector<int> > dp;
        dp.resize(ls + 5);
        for (auto iter = dp.begin(); iter != dp.end(); ++iter) {
            iter -> resize(lt + 5);
        }
        for (int i = 0; i <= ls; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < lt; i++) {
            for (int j = 0; j < ls; j++) {
                if (T[i] == S[j]) {
                    dp[j + 1][i + 1] += dp[j][i] + dp[j][i + 1];
                } else {
                    dp[j + 1][i + 1] += dp[j][i + 1];
                }
            }
        }
        return dp[ls][lt];
    }
};
