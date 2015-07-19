class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        
        res[0] = nums[n - 1];
        res[n - 1] = nums[0];
        for (int i = 1; i < n - 1; i++) {
            res[i] *= res[n - 1];
            res[n - 1 - i] *= res[0];
            
            res[0] *= nums[n - 1 - i];
            res[n - 1] *= nums[i];
        }
        return res;
    }
};
