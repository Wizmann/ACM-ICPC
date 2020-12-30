const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, i, j, n, m));
                }
            }
        }
        
        return ans;
    }
    
private:
    int dfs(vector<vector<int> >& grid, int y, int x, int n, int m) {
        if (grid[y][x] != 1) {
            return 0;
        }
        
        int res = 1;
        grid[y][x] = -1;
        for (int i = 0; i < 4; i++) {
            int ny = y + my[i];
            int nx = x + mx[i];
            
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }
            
            res += dfs(grid, ny, nx, n, m);
        }
        return res;
    }
};
