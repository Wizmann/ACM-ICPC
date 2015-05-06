class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n <= 1) {
            return;
        }
        int m = matrix[0].size();
        if (m <= 1) {
            return;
        }
        
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                int y = i;
                int x = j;
                int aux = matrix[y][x];
                for (int k = 0; k < 4; k++) {
                    int ny = x;
                    int nx = n - 1 - y;
                    swap(matrix[ny][nx], aux);
                    y = ny;
                    x = nx;
                }
            }
        }
    }
};
