class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int m = matrix[0].size();
        if (m == 0) {
            return 0;
        }
        
        int y = 0;
        int x = m - 1;
        
        int ans = 0;
        while (y < n && x >= 0) {
            int u = matrix[y][x];
            
            if (u == target) {
                ans++;
            }
            
            if (u >= target) {
                x--;
            } else {
                y++;
            }
        }
        return ans;
    }
};

