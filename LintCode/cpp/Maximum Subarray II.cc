class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        int n = nums.size();
        
        vector<int> A = do_max_subarray(nums);
        reverse(nums.begin(), nums.end());
        vector<int> B = do_max_subarray(nums);
        
        int ans = numeric_limits<int>::min();
        for (int i = 0, j = n - 2; i < n && j >= 0; i++, j--) {
            ans = max(ans, A[i] + B[j]);
        }
        return ans;
    }
private:
    vector<int> do_max_subarray(const vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int sum = 0;
        int maxi = numeric_limits<int>::min();
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            res[i] = maxi;
            
            sum = max(sum, 0);
        }
        return res;
    }
};

