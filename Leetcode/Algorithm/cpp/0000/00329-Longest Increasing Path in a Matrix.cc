const int mx[4] = {0, 1, 0, -1};
const int my[4] = {-1, 0, 1, 0};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        _n = matrix.size();
        
        if (_n == 0) {
            return 0;
        }
        
        _m = matrix[0].size();
        
        if (_m == 0) {
            return 0;
        }
        _matrix = matrix;
        _dp = vector<vector<int> >(_n, vector<int>(_m, -1));
        int ans = 0;
        for (int i = 0; i < _n; i++) {
            for (int j = 0; j < _m; j++) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
private:
    int dfs(int y, int x) {
        if (_dp[y][x] != -1) {
            return _dp[y][x];
        }
        
        _dp[y][x] = 1;
        multimap<int, int> mp;
        for (int i = 0; i < 4; i++) {
            int nx = x + mx[i];
            int ny = y + my[i];
            if (!in_board(ny, nx)) {
                continue;
            }
            if (_matrix[ny][nx] >= _matrix[y][x]) {
                continue;
            }
            mp.insert({_matrix[ny][nx], i});
        }
        
        for (auto iter = mp.rbegin(); iter != mp.rend(); ++iter) {
            int ny = y + my[iter->second];
            int nx = x + mx[iter->second];
            
            _dp[y][x] = max(_dp[y][x], dfs(ny, nx) + 1);
        }
        
        return _dp[y][x];
    }
    
    bool in_board(int y, int x) {
        return y >= 0 && y < _n && x >= 0 && x < _m;
    }
private:
    int _n;
    int _m;
    vector<vector<int> > _dp;
    vector<vector<int> > _matrix;
};
