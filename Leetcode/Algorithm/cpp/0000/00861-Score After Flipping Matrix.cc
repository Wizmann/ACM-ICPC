class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size();
        if (n == 0) {
            return 0;
        }
        
        int m = A[0].size();
        if (m == 0) {
            return 0;
        }
        
        return max(solve(A, n, m, 0), solve(A, n, m, 1));
    }
private:
    int solve(vector<vector<int> >& A, const int n, const int m, int init) {
        int res = n * (1 << (m - 1));
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = A[i][0] ^ init ^ 1;
        }
        for (int j = 1; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += A[i][j] ^ p[i];
            }
            res += (1 << (m - j - 1)) * max(cnt, n - cnt);
        }
        return res;
    }
};
