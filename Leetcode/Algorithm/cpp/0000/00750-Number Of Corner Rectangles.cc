class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        vector<pair<int, int> > points;
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                points.push_back({i, j});
            }
        }
        
        int res = 0;
        int k = points.size();
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                int y1 = points[i].first;
                int x1 = points[i].second;
                int y2 = points[j].first;
                int x2 = points[j].second;
                
                if (y1 == y2 || x1 == x2) {
                    continue;
                }
                
                if (grid[y1][x2] && grid[y2][x1]) {
                    res++;
                }
            }
        }
        return res / 2;
    }
};
