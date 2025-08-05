const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix_) {
        matrix = matrix_;
        
        n = matrix.size();
        if (n == 0) {
            return {};
        }
        m = matrix[0].size();
        
        dp = vector<vector<int> >(n);
        for (int i = 0; i < n; i++) {
            dp[i] = vector<int>(m, 0);
        }
        
        for (int i = 0; i < n; i++) {
            dfs(i, 0, 1, -1);
            dfs(i, m - 1, 2, -1);
        }
        
        for (int i = 0; i < m; i++) {
            dfs(0, i, 1, -1);
            dfs(n - 1, i, 2, -1);
        }
        
        vector<pair<int, int> > res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == 3) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
private:
    void dfs(int y, int x, int u, int pre) {
        if (dp[y][x] & u) {
            return;
        }
        
        if (matrix[y][x] < pre) {
            return;
        }

        dp[y][x] |= u;
        
        for (int i = 0; i < 4; i++) {
            int ny = y + my[i];
            int nx = x + mx[i];
            
            if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                dfs(ny, nx, u, matrix[y][x]);
            }
        }
    }
private:
    int n, m;
    vector<vector<int> > dp;
    vector<vector<int> > matrix;
};
