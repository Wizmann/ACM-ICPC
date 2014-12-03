class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        if (A.empty()) {
            return 0;
        }
        int n = A.size();
        int ptr = 0;
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < n; i++) {
            int cur = A[i];
            int next = ptr ^ 1;
            memset(dp[next], INF, sizeof(dp[next]));
            for (int j = 1; j <= 100; j++) {
                int diff = abs(cur - j);
                int range_l = max(1, j - target);
                int range_r = min(100, j + target);
                for (int k = range_l; k <= range_r; k++) {
                    dp[next][j] = min(dp[next][j], dp[ptr][k] + diff);
                }
            }
            ptr ^= 1;
        }
        int ans = INF;
        for (int i = 1; i <= SIZE; i++) {
            ans = min(ans, dp[ptr][i]);
        }
        return ans;
    }
private:
    static const int SIZE = 100;
    static const int INF  = 0x3f3f3f3f;
    int dp[2][SIZE + 5];
};
