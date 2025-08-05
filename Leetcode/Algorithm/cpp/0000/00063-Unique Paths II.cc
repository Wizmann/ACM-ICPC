const int SIZE = 128;
int dp[SIZE + 5][SIZE + 5];

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        memset(dp, 0, sizeof(dp));
        
        int n = obstacleGrid.size();
        int m = n? obstacleGrid[0].size(): -1;
        dp[0][0] = obstacleGrid[0][0] == 0? 1 : 0;
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int nx, ny;
                ny = i + 1; nx = j;
                if (ny < n && nx < m && obstacleGrid[ny][nx] == 0) {
                    dp[ny][nx] += dp[i][j];
                }
                ny = i; nx = j + 1;
                if (ny < n && nx < m && obstacleGrid[ny][nx] == 0) {
                    dp[ny][nx] += dp[i][j];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
