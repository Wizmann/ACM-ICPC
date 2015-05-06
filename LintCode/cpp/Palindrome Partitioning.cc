class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        int n = s.length();
        res.clear();
        
        if (n == 0) {
            return res;
        }
        init_dp(s, n);

        vector<string> tmp;
        dfs(0, n, s, tmp);
        
        return res;
    }
private:
    void init_dp(const string& s, int n) {
        dp.clear();
        dp.resize(n);
        for (auto& _dp: dp) {
            _dp.resize(n);
            fill(_dp.begin(), _dp.end(), 0);
        }
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; i + j < n; j++) {
                if (s[j] != s[j + i]) {
                    continue;
                }
                dp[j][j + i] = i == 1 || dp[j + 1][j + i - 1];
            }
        }
    }
    
    void dfs(int u, int n, const string& s, vector<string>& tmp) {
        if (u == n) {
            res.push_back(tmp);
            return;
        }
        for (int i = u; i < n; i++) {
            if (dp[u][i]) {
                tmp.push_back(s.substr(u, i - u + 1));
                dfs(i + 1, n, s, tmp);
                tmp.pop_back();
            }
        }
    }
private:
    vector<vector<string> > res;
    vector<vector<int> > dp;
};
