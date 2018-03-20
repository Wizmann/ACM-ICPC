const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid_, vector<vector<int>>& hits) {
        grid = grid_;
        n = grid.size();
        m = grid[0].size();
        
        tot = 0;
        
        for (auto hit: hits) {
            int y = hit[0];
            int x = hit[1];
            
            grid[y][x]--;
        }
        
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1) {
                dfs(0, i);
            }
        }
        
        vector<int> res;
        int pre = tot;
        for (auto iter = hits.rbegin(); iter != hits.rend(); ++iter) {
            int y = *(iter->begin());
            int x = *(iter->rbegin());
            grid[y][x]++;
            
            if (grid[y][x] != 1) {
                res.push_back(0);
                continue;
            }
            
            for (int i = 0; i < 4; i++) {
                int ny = y + my[i];
                int nx = x + mx[i];
                
                if (y == 0 || (0 <= ny && ny < n && 0 <= nx && nx < m && grid[ny][nx] == 2)) {
                    dfs(y, x);
                    break;
                }
            }
            if (tot > pre) {
                pre++;
            }
            res.push_back(tot - pre);
            pre = tot;
        }
        reverse(res.begin(), res.end());
        return res;
    }
private:
    int get_nr(int y, int x) {
        return y * m + x + 1;
    }
    
    void dfs(int y, int x) {
        if (grid[y][x] == 2) {
            return;
        }
        
        grid[y][x] = 2;
        tot++;
        for (int i = 0; i < 4; i++) {
            int ny = y + my[i];
            int nx = x + mx[i];
            
            if (0 <= ny && ny < n && 0 <= nx && nx < m && grid[ny][nx] == 1) {
                dfs(ny, nx);
            }
        }
    }
private:
    int n;
    int m;
    int tot;
    vector<vector<int>> grid;
};
