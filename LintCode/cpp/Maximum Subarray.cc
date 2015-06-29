class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int sum = 0;
        int ans = numeric_limits<int>::min();
        
        for (auto n: nums) {
            sum += n;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};

