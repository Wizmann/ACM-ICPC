const int mx[] = {0, 1, 0, -1};
const int my[] = {1, 0, -1, 0};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();
        if (m == 0) {
            return 0;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int ny = i + my[k];
                    int nx = j + mx[k];
                    
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                        cnt++;
                    } else if (grid[ny][nx] == 0) {
                        cnt++;
                    }
                }
                ans += cnt;
                //cout << i << ' ' << j << ' ' << cnt << endl;
            }
        }
        return ans;
    }
};
