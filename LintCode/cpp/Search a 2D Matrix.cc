class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        if (n == 0) {
            return false;
        }
        int m = matrix[0].size();
        if (m == 0) {
            return false;
        }
        
        int y = n - 1;
        int x = 0;
        while (y >= 0 && x < m) {
            int u = matrix[y][x];
            if (u == target) {
                return true;
            } else if (u < target) {
                x++;
            } else {
                y--;
            }
        }
        return false;
    }
};

