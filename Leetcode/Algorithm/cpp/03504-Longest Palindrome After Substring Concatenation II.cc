class Solution {
public:
    int longestPalindrome(string s, string t) {
        int a = solve(s, t);
        reverse(t.begin(), t.end());
        reverse(s.begin(), s.end());
        int b = solve(t, s);
        return max(a, b);
    }

    int solve(const string& s, const string& t) {
        int n = s.size();
        vector<vector<int> > dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = vector<int>(n, 0);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            for (int j = 1; j < n; j++) {
                int l = i - j;
                int r = i + j;
                if (l < 0 || r >= n) {
                    break;
                }
                if (s[l] == s[r]) {
                    dp[l][r] = 1;
                } else {
                    break;
                }
            }

            for (int j = 0; j < n; j++) {
                int l = i - j;
                int r = i + 1 + j;
                if (l < 0 || r >= n) {
                    break;
                }
                if (s[l] == s[r]) {
                    dp[l][r] = 1;
                } else {
                    break;
                }
            }
        }

        vector<int> maxp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dp[i][j]) {
                    maxp[i] = max(maxp[i], j - i + 1);
                    res = max(res, j - i + 1);
                }
            }
        }

        int m = t.size();
        vector<vector<int> > mp(n);
        for (int i = 0; i < n; i++) {
            mp[i] = vector<int>(m, -1);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i] == t[j]) {
                    // cout << s[i] << ' ' << t[j] << ' ' << maxp[i + 1] << std::endl;
                    res = max(res, dfs(mp, s, t, i, j) + maxp[i + 1]);
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int> >& mp, const string& s, const string& t, int l, int r) {
        if (l < 0 || r >= t.size()) {
            return 0;
        }
        if (mp[l][r] != -1) {
            return mp[l][r];
        }
        if (s[l] == t[r]) {
            int res = dfs(mp, s, t, l - 1, r + 1) + 2;
            // cout << res << endl;
            return mp[l][r] = res;
        } else {
            return 0;
        }
    }
};
