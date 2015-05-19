class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        int cnt = 0;
        vector<int> res;
        
        int n = matrix.size();
        if (n == 0) {
            return res;
        }
        int m = matrix[0].size();
        if (m == 0) {
            return res;
        }
        
        for (int i = 0; i < m + n - 1; i++) {
            int y = max(0, i - m + 1);
            int x = min(i, m - 1);
            
            vector<int> tmp;
            
            while (true) {
                tmp.push_back(matrix[y][x]);
                y += 1;
                x -= 1;
                if (x < 0 || y < 0 || x >= m || y >= n) {
                    break;
                }
            }
            
            if (cnt % 2 == 0) {
                reverse(tmp.begin(), tmp.end());
            }
            copy(tmp.begin(), tmp.end(), back_inserter(res));
            cnt++;
        }
        return res;
    }
};
