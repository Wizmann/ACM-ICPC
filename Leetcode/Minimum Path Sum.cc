const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        vector<vector<int> > dp;
        dp.resize(grid.size());
        for (auto iter = dp.begin(); iter != dp.end(); ++iter) {
            iter -> resize(grid[0].size());
            fill(iter -> begin(), iter -> end(), INF);
        }
        dp[0][0] = grid[0][0];
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i - 1 >= 0) dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j]);
                if (j - 1 >= 0) dp[i][j] = min(dp[i][j - 1] + grid[i][j], dp[i][j]);
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
