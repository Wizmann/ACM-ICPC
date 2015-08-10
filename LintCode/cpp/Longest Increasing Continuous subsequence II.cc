const int my[] = {-1, 0, 1, 0};
const int mx[] = {0, 1, 0, -1};

class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        n = A.size();
        
        if (n == 0) {
            return 0;
        }
        
        m = A[0].size();
    
        dp.resize(n);
        for (auto& _dp: dp) {
            _dp = vector<int>(m, -1);
        }
        
        int ans = 0;    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(A, i, j));
            }
        }
        
        return ans;
    }
private:
    int dfs(vector<vector<int>>& A, int y, int x) {
        if (dp[y][x] != -1) {
            return dp[y][x];
        }
        
        dp[y][x] = 1;
        for (int i = 0; i < 4; i++) {
            int ny = y + my[i];
            int nx = x + mx[i];
            
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }
            
            if (A[ny][nx] > A[y][x]) {
                dp[y][x] = max(dp[y][x], dfs(A, ny, nx) + 1);
            }
        }
        return dp[y][x];
    }
private:
    int n;
    int m;
    vector<vector<int> > dp;
};
