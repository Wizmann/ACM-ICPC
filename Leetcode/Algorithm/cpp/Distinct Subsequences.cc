class Solution {
public:
    int numDistinct(string S, string T) {
        int l1 = S.size();
        int l2 = T.size();
        dp.clear();
        dp.resize(l1 + 3);
        for (auto& subvec: dp) {
            subvec.resize(l2 + 3);
        }
 
        for (int i = 0; i <= l1; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (S[i - 1] == T[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                dp[i][j] += dp[i - 1][j];
            }
        }
        return dp[l1][l2];
    }
private:
    vector<vector<int> > dp;
};
