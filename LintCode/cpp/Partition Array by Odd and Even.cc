class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r) {
            while (l <= r && nums[l] % 2 == 1) {
                l++;
            }
            while (l <= r && nums[r] % 2 == 0) {
                r--;
            }
            if (l <= r) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
    }
};
