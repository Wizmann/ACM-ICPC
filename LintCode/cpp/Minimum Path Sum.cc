class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (n == 1 && m == 1) {
            return grid[0][0];
        }
        
        const int INF = 0x3f3f3f3f;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int a = j - 1 >= 0? grid[i][j - 1]: INF;
                int b = i - 1 >= 0? grid[i - 1][j]: INF;
                grid[i][j] += min(a, b);
            }
        }
        return grid[n - 1][m - 1];
    }
};

