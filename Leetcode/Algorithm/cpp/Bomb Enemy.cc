class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();
        if (m == 0) {
            return 0;
        }
        
        vector<vector<int> > res(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            int pre = 0;
            for (int j = 0; j < m; j++) {
                res[i][j] += deal(grid[i][j], pre);
            }
            
            pre = 0;
            for (int j = m - 1; j >= 0; j--) {
                res[i][j] += deal(grid[i][j], pre);
            }
        }
        
        for (int j = 0; j < m; j++) {
            int pre = 0;
            for (int i = 0; i < n; i++) {
                res[i][j] += deal(grid[i][j], pre);
            }
            
            pre = 0;
            for (int i = n - 1; i >= 0; i--) {
                res[i][j] += deal(grid[i][j], pre);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, res[i][j] - 4 * (grid[i][j] == 'E'));
            }
        }
        return ans;
    }
private:
    int deal(char c, int& pre) {
        if (c == 'E') {
            pre++;
        } else if (c == 'W') {
            pre = 0;
        }
        return c == '0'? pre: 0;
    }
};
