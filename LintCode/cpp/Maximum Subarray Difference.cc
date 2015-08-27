class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        int ans = do_maxDiffSubArrays(nums);
        reverse(nums.begin(), nums.end());
        ans = max(ans, do_maxDiffSubArrays(nums));
        return ans;
    }
    
    int do_maxDiffSubArrays(vector<int> nums) {
        int n = nums.size();
        vector<int> maxi(n, 0);
        vector<int> mini(n, 0);
        
        for (int i = 0, sum = 0; i < n; i++) {
            sum += nums[i];
            maxi[i] = i - 1 >= 0? maxi[i - 1]: numeric_limits<int>::min();
            maxi[i] = max(maxi[i], sum);
            sum = max(sum, 0);
        }
        
        for (int i = n - 1, sum = 0; i >= 0; i--) {
            sum += nums[i];
            mini[i] = i + 1 < n? mini[i + 1]: numeric_limits<int>::max();
            mini[i] = min(mini[i], sum);
            sum = min(sum, 0);
        }
        
        int ans = numeric_limits<int>::min();
        for (int i = 0; i + 1< n; i++) {
            ans = max(ans, maxi[i] - mini[i + 1]);
        }
        return ans;
    }
};

