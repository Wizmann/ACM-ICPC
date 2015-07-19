class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        int sum = 0;
        int mini = numeric_limits<int>::max();
        
        for (auto i: nums) {
            sum += i;
            mini = min(mini, sum);
            sum = min(0, sum);
        }
        return mini;
    }
};

