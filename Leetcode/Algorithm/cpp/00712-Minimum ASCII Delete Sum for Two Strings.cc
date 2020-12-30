const int SIZE = 1111;
const int INF = 0x3f3f3f3f;

int dp[SIZE][SIZE];

class Solution {
public:
    int minimumDeleteSum(string s1_, string s2_) {
        s1 = s1_;
        s2 = s2_;
        
        memset(dp, INF, sizeof(dp));
        n = s1.size();
        m = s2.size();
        
        return dfs(0, 0);
    }
private:
    int dfs(int a, int b) {
        // cout << a << ' ' << b << ' ' << n << ' ' << m << ' ' << dp[a][b] << endl;
        if (a == n && b == m) {
            return 0;
        }
        
        if (dp[a][b] != INF) {
            return dp[a][b];
        }
        
        if (a < n && b < m && s1[a] == s2[b]) {
            return dp[a][b] = dfs(a + 1, b + 1);
        } else {
            int res = INF;
            if (a < n) {
                res = min(res, s1[a] + dfs(a + 1, b));
            }
            if (b < m) {
                res = min(res, s2[b] + dfs(a, b + 1));
            }
            return dp[a][b] = res;
        }
    }
private:
    string s1, s2;
    int n, m;
};
