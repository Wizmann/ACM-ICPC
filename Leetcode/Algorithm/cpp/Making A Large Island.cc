const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};
const int MASK = 65536;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 0) {
            return 0;
        }
        m = grid[0].size();
        if (m == 0) {
            return 0;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = -grid[i][j];
            }
        }
        
        int ans = 0;
        int idx = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == -1) {
                    buffer.clear();
                    int size = dfs(grid, i, j);
                    for (auto p: buffer) {
                        grid[p.first][p.second] = size + idx * MASK;
                    }
                    idx++;
                    ans = max(ans, min(n * m, size + 1));
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    continue;
                }
                
                vector<int> islands;
                for (int k = 0; k < 4; k++) {
                    islands.push_back(island_size(grid, i, j, k));
                }
                sort(islands.begin(), islands.end());
                
                int s = islands[0] % MASK;
                for (int k = 1; k < 4; k++) {
                    if (islands[k - 1] / MASK == islands[k] / MASK) {
                        continue;
                    }
                    s += islands[k] % MASK;
                }
                ans = max(ans, s + 1);
            }
        }
        return max(1, ans);
    }
private:
    int island_size(vector<vector<int>>& grid, int y, int x, int mv) {
        int ny = y + my[mv];
        int nx = x + mx[mv];
        
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
            return 0;
        }
        
        return grid[ny][nx];
    }
    
    int dfs(vector<vector<int>>& grid, int y, int x) {
        int cnt = 1;
        buffer.push_back({y, x});
        grid[y][x] = -2;
        
        for (int i = 0; i < 4; i++) {
            int ny = y + my[i];
            int nx = x + mx[i];
            
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }
            
            if (grid[ny][nx] == -1) {
                cnt += dfs(grid, ny, nx);
            }
        }
        
        return grid[y][x] = cnt;
    }
private:
    int n, m;
    vector<pair<int, int> > buffer;
};
