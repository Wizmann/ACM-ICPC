typedef long long llint;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (llint i = 0; i <= target; i++) {
            for (auto num: nums) {
                if (dp[i] && i + num <= target) {
                    dp[i + num] += dp[i];
                }
            }
        }
        return dp[target];
    }
};
