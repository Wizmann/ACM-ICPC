class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }
        int u = sum / k;
        
        vector<int> masks;
        
        for (int i = 0; i < 1 << n; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    s += nums[j];
                }
            }
            if (s == u) {
                masks.push_back(i);
            }
        }
        
        vector<bool> dp(1 << n, false);
        dp[0] = true;
        
        for (auto mask: masks) {
            for (int i = 0; i < 1 << n; i++) {
                if (dp[i] && (i & mask) == 0) {
                    dp[i | mask] = true;
                }
            }            
        }
        return dp[(1 << n) - 1];
    }
};
