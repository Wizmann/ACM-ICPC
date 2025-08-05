typedef long long llint;

const int MOD = 1000000000 + 7;

class Solution {
public:
    int numPermsDISequence(string S) {
        S = "I" + S;
        int n = S.size();
        
        memset(dp, -1, sizeof(dp));
        
        return dfs(S, 0, 0, n);
    }
    
    int dfs(const string& S, int cur, int lt, int gt) {
        if (S.size() == cur) {
            return 1;
        }
        if (dp[lt][gt] != -1) {
            return dp[lt][gt];
        }
        llint ans = 0;
        if (S[cur] == 'I') {
            for (int i = 0; i < gt; i++) {
                ans += dfs(S, cur + 1, lt + i, gt - i - 1);
                ans %= MOD;
            }
        } else {
            for (int i = 0; i < lt; i++) {
                ans += dfs(S, cur + 1, i, gt + lt - i - 1);
                ans %= MOD;
            }
        }
        return dp[lt][gt] = ans;
    }
private:
    int dp[202][202];
};
