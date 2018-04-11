const int INF = 0x3f3f3f3f;

class Solution {
public:
    string minWindow(string S, string T) {
        int n = S.size();
        int m = T.size();
        vector<int> dp[2];
        int p = 0;
        dp[0] = vector<int>(n, -INF);
        dp[1] = vector<int>(n, -INF);
        
        for (int i = 1; i <= m; i++) {
            int q = p ^ 1;
            fill(dp[q].begin(), dp[q].end(), -INF);
            
            int pre = -INF;
            for (int j = 0; j < n; j++) {
                if (S[j] == T[i - 1]) {
                    if (i == 1) {
                        dp[q][j] = j;
                    } else {
                        dp[q][j] = pre;
                    }
                }
                
                pre = max(pre, dp[p][j]);
            }
            p = q;
        }
        string res;
        int mini = INF;
        for (int i = 0; i < n; i++) {
            int l = i - dp[p][i] + 1;
            if (l < mini) {
                mini = l;
                res = S.substr(dp[p][i], l);
            }
        }
        return res;
    }
};
