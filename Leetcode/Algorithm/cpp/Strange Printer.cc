const int SIZE = 111;
const int INF = 0x3f3f3f3f;

#define print(x) cout << x << endl

class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) {
            return 0;
        }
        memset(dp, INF, sizeof(dp));
        int n = s.size();
        return dfs(s, 0, n - 1);
    }
private:
    int dfs(const string& s, int l, int r) {
        if (dp[l][r] != INF) {
            return dp[l][r];
        }
        
        if (l == r) {
            return dp[l][r] = 1;
        }
        
        int res = strip_dfs(s, l, r, s[l]);
        for (int i = l; i <= r; i++) {
            for (int j = i; j <= r; j++) {
                if (s[i] != s[j]) {
                    continue;
                }
                res = min(res, strip_dfs(s, l, i - 1, s[i]) + strip_dfs(s, i, j, s[i]) + strip_dfs(s, j, r, s[i]));
            }
        }
        return dp[l][r] = res + 1;
    }
    
    int strip_dfs(const string& s, int l, int r, char c) {
        if (l > r) {
            return 0;
        }
        while (l <= r && s[l] == c) {
            l++;
        }
        while (l <= r && s[r] == c) {
            r--;
        }
        if (l <= r) {
            return dfs(s, l, r);
        } else {
            return 0;
        }
    }
private:
    int dp[SIZE][SIZE];
};
