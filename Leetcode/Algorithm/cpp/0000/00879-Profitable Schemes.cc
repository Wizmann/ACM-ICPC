const int MOD = 1000000000 + 7;

class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        dp = vector<vector<int> >(G + 1, vector<int>(P + 1));
        dp[0][0] = 1;
        
        const int n = group.size();
        for (int i = 0; i < n; i++) {
            int g = group[i];
            int p = profit[i];
            
            for (int j = G; j >= 0; j--) {
                for (int k = P; k >= 0; k--) {
                    if (dp[j][k] != 0 && j + g <= G) {
                        dp[j + g][min(P, k + p)] += dp[j][k];
                        dp[j + g][min(P, k + p)] %= MOD;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= G; i++) {
            ans += dp[i][P];
            ans %= MOD;
        }
        return ans;
    }
private:
    vector<vector<int> > dp;
};
