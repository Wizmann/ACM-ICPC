const int INF = 0x3f3f3f3f;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> &nums, int k) {
        n = nums.size();
        
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        
        dp = vector<vector<int> >(2, vector<int>(n, -INF));
        
        for (int i = 0; i < n; i++) {
            dp[0][i] = -INF;
            for (int j = 0; j <= i; j++) {
                dp[0][i] = max(dp[0][i], nums[i] - (j - 1 < 0? 0: nums[j - 1]));
            }
            if (i - 1 >= 0) {
                dp[0][i] = max(dp[0][i], dp[0][i - 1]);
            }
        }
        
        int cur = 0;
        for (int i = 1; i < k; i++) {
            int ptr = cur ^ 1;
            dp[ptr] = vector<int>(n, -INF);
            for (int j = i; j < n; j++) {
                for (int jj = i; jj <= j; jj++) {
                    int sum = nums[j] - nums[jj - 1];
                    dp[ptr][j] = max(dp[ptr][j], dp[cur][jj - 1] + sum);
                }
                dp[ptr][j] = max(dp[ptr][j], dp[ptr][j - 1]);
            }
            cur = ptr;
        }
        
        return dp[cur][n - 1];
    }
private:
    vector<vector<int> > dp;
    int n;
};
