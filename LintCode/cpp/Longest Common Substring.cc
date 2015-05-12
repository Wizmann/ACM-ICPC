class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int n = A.size();
        int m = B.size();
        
        init(n, m);
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i] == B[j]) {
                    dp[i][j] = 
                        (i - 1 >= 0 && j - 1 >= 0? dp[i - 1][j - 1]: 0) + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
private:
    void init(int n, int m) {
        dp.resize(n);
        for (auto& _dp: dp) {
            _dp.resize(m);
            fill(_dp.begin(), _dp.end(), 0);
        }
    }
private:
    vector<vector<int> > dp;
};

