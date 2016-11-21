class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0, plus<int>());
        
        if (sum % 2 != 0) {
            return false;
        }
        
        int maxi = sum / 2 + 100;
        vector<bool> dp(maxi, false);
        dp[0] = true;
        for (auto num: nums) {
            for (int i = maxi - num; i >= 0; i--) {
                if (dp[i] && i + num < maxi) {
                    dp[i + num] = true;
                }
                if (dp[sum / 2]) {
                    return true;
                }
            }
        }
        return (sum % 2 == 0 && dp[sum / 2]);
    }
};
