class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n == 0) {
            return;
        }
        int m = matrix[0].size();
        if (m == 0) {
            return;
        }
        
        int first_row = 1;

        for (int i = 0; i < m; i++) {
            first_row &= matrix[0][i]? 1: 0;
        }
        
        for (int i = 1; i < n; i++) {
            int zero_cnt = 0;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j]) {
                    continue;
                }
                matrix[0][j] = 0;
                zero_cnt++;
            }
            if (zero_cnt) {
                fill_row(matrix, i, 0);
            }
        }

        for (int i = 0; i < m; i++) {
            if (matrix[0][i] == 0) {
                fill_col(matrix, i, 0);
            }
        }
        
        if (first_row == 0) {
            fill_row(matrix, 0, 0);
        }

    }
    
    void fill_col(vector<vector<int> >& matrix, int col, int val) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            matrix[i][col] = val;   
        }
    }
    
    void fill_row(vector<vector<int> >& matrix, int row, int val) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < m; i++) {
            matrix[row][i] = val;   
        }
    }
};
