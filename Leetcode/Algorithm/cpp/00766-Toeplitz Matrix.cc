class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        
        for (int i = 0; i < n; i++) {
            if (!check(matrix, i, 0)) {
                return false;
            }
        }
        
        for (int i = 0; i < m; i++) {
            if (!check(matrix, 0, i)) {
                return false;
            }
        }
        
        return true;
    }
    
private:
    bool check(vector<vector<int>>& matrix, int y, int x) {
        int u = matrix[y][x];
        while (y < n && x < m) {
            int v = matrix[y][x];
            if (u != v) {
                return false;
            }
            y += 1;
            x += 1;
        }
        return true;
    }
    
    int n, m;
};
