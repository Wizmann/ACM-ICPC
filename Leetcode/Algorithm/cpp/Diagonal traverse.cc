class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int mx = +1;
        int my = -1;
        int dir = 1;
        
        int n = matrix.size();
        if (n == 0) {
            return {};
        }
        int m = matrix[0].size();
        if (m == 0) {
            return {};
        }
        vector<int> res;
        
        int x = 0;
        int y = 0;
        for (int i = 0; i < n * m; i++) {
            res.push_back(matrix[y][x]);

            int ny = y + my * dir;
            int nx = x + mx * dir;
            
            if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                y = ny;
                x = nx;
            } else {
                if (x + 1 < m && (y == 0 || y == n - 1)) {
                    x++;
                } else {
                    y++;
                }
                dir *= -1;
            }
        }
        return res;
    }
};
