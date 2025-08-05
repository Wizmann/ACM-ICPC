class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        size_t n = dungeon.size();
        
        if (n == 0) {
            return 0;
        }
        
        size_t m = dungeon[0].size();
        
        int l = 1, r = INF;
        
        while (l <= r) {
            dp_resize(n, m);
            int mid = (l & r) + ((l ^ r) >> 1);
            if (solve(dungeon, n, m, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r + 1;
    }
private:
    bool solve(vector<vector<int> > &dungeon, int n, int m, int v) {
        dp[0][0] = v + dungeon[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                dp[i][j] = -INF;
                if (i - 1 >= 0) {
                    if (dp[i - 1][j] > 0) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j] + dungeon[i][j]);
                    }
                }
                if (j - 1 >= 0) {
                    if (dp[i][j - 1] > 0) {
                        dp[i][j] = max(dp[i][j], dp[i][j - 1] + dungeon[i][j]);
                    }
                }
            }
        }
        return dp[n - 1][m - 1] > 0;
    }
    void dp_resize(size_t n, size_t m) {
        dp.clear();
        dp.resize(n);
        for (auto& subvec: dp) {
            subvec.resize(m);
        }
    }
private:
    vector<vector<int> > dp;
private:
    static const int INF = 0x3f3f3f3f;
};
