class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        int n = matrix.size();
        // assert (n != 0);
        int m = matrix[0].size();
        // assert (m != 0);
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    continue;
                }
                
                if (i - 1 >= 0 && j - 1 >= 0) {
                    int s = INF;
                    s = min(s, matrix[i - 1][j]);
                    s = min(s, matrix[i][j - 1]);
                    s = min(s, matrix[i - 1][j - 1]);
                    
                    matrix[i][j] = s + 1;
                }
                
                ans = max(ans, matrix[i][j]);
            }
        }
        return ans * ans;
    }
private:
    static const int INF = 0x3f3f3f3f;
};
