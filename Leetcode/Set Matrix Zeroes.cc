class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int m = n > 0? matrix[0].size(): -1;
        if (n <= 0) {
            return;
        }
        
        int first_line = 1;
        for (int i = 0; i < m; i++) {
            first_line = matrix[0][i]? first_line: 0;
        }
        
        for (int i = 1; i < n; i++) {
            int val = 1;
            for (int j = 0; j < m; j++) {
                val = matrix[i][j]? val: 0;
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                }
            }
            if (val) {
                continue;
            }
            for (int j = 0; j < m; j++) {
                matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            if (matrix[0][i]) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                matrix[j][i] = 0;
            }
        }
        if (first_line == 0) {
            for (int i = 0; i < m; i++) {
                matrix[0][i] = 0;
            }
        }
    }
};
