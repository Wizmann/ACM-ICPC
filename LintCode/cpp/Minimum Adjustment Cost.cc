const int SIZE = 1024;
const int MAXI = 123;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        memset(dp, INF, sizeof(dp));
        int n = A.size();
        for (int i = 0; i < MAXI; i++) {
            dp[0][i] = abs(i - A[0]);
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < MAXI; j++) {
                int l = max(0, j - target);
                int r = min(MAXI, j + target);
                for (int k = l; k <= r; k++) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(j - A[i]));
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < MAXI; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
private:
    int dp[SIZE][MAXI];
};
