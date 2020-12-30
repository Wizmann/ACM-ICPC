class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n);
    }
private:
    int solve(const vector<int>& nums, int l, int r) {
        if (r - l == 1) {
            return nums[l];
        }
        int m = (l + r) >> 1;
        if (nums[m] == nums[m + 1]) {
            m++;
        }
        
        if ((m + 1 - l) % 2 == 0) {
            return solve(nums, m + 1, r);
        } else {
            return solve(nums, l, m - 1);
        }
    }
};
