class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (!n) {
            return;
        }
        
        int m = matrix[0].size();
        
        set<int> zero_row;
        set<int> zero_col;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!matrix[i][j]) {
                    zero_row.insert(i);
                    zero_col.insert(j);
                }
            }
        }
        
        for (set<int>::iterator iter = zero_row.begin();
                iter != zero_row.end();
                ++iter) {
            int y = *iter;
            for (int i = 0; i < m; i++) {
                matrix[y][i] = 0;
            }
        }
        
        for (set<int>::iterator iter = zero_col.begin();
                iter != zero_col.end();
                ++iter) {
            int x = *iter;
            for (int i = 0; i < n; i++) {
                matrix[i][x] = 0;
            }
        }
    }
};
