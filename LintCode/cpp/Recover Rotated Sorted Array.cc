class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        int n = nums.size();
        int offset = -1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                offset = i;
            }
        }
        if (offset == -1) {
            return;
        }
        
        reverse(nums.begin(), nums.begin() + offset);
        reverse(nums.begin() + offset, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
