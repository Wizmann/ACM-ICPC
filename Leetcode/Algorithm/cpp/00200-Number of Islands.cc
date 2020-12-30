const int MOV_NUM = 4;
const int my[MOV_NUM] = {-1, 0, 1, 0};
const int mx[MOV_NUM] = {0, 1, 0, -1};

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        n = grid.size();
        
        if (n == 0) {
            return 0;
        }
        
        m = grid[0].size();
        
        if (m == 0) {
            return 0;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<char>> &grid, int y, int x) {
        grid[y][x] = 2;
        for (int i = 0; i < MOV_NUM; i++) {
            int ny = y + my[i];
            int nx = x + mx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }
            if (grid[ny][nx] != '1') {
                continue;
            }
            dfs(grid, ny, nx);
        }
    }
private:
    int n;
    int m;
};
