class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        int n = A.size();
        
        for (int i = 0; i < n; i++) {
            int weight = A[i];
            int value  = V[i];
            for (int j = m; j >= 0; j--) {
                if (dp[j] != -1 && j + weight <= m) {
                    dp[j + weight] = max(dp[j + weight], dp[j] + value);
                }
            }
        }
        
        int ans = 0;
        for (int i = m; i >= 0; i--) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
private:
    static const int SIZE = 1024;
    int dp[SIZE];
};
