class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        _matrix = matrix;
        _n = _matrix.size();
        if (_n == 0) {
            _m = 0;
            return;
        }
        _m = _matrix[0].size();
        
        for (int i = _m - 1; i >= 0; i--) {
            int sum = 0;
            for (int j = _n - 1; j >= 0; j--) {
                sum += _matrix[j][i];
                _matrix[j][i] = sum + (i + 1 < _m? _matrix[j][i + 1]: 0);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = _matrix[row1][col1];
        int b = row2 + 1 < _n? _matrix[row2 + 1][col1]: 0;
        int c = col2 + 1 < _m? _matrix[row1][col2 + 1]: 0;
        int d = row2 + 1 < _n && col2 + 1 < _m? _matrix[row2 + 1][col2 + 1]: 0;
        
        return a - b - c + d;
    }
private:
    int _n;
    int _m;
    vector<vector<int> > _matrix;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
