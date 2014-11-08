class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int y = 0;
        
        while (true) {
            int mini = matrix[y][0];
            int maxi = matrix[y][m - 1];
            
            if (mini <= target && maxi >= target) {
                for (int i = 0; i < m; i++) {
                    if (matrix[y][i] == target) {
                        return true;
                    }
                }
                return false;
            } else if (y + 1 < n) {
                y++;
            } else {
                break;
            }
        }
        return false;
    }
};
