class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int y = 0;
        int x = m - 1;
        
        while (y >= 0 && y < n && x >= 0 && x < m) {
            int u = matrix[y][x];
            if (u > target) {
                x--;
            } else if (u < target) {
                y++;
            } else {
                return true;
            }
        }
        return false;
    }
};
