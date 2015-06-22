class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                do_next_perm(nums, i, n);
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
private:
    void do_next_perm(vector<int>& nums, int pos, int n) {
        int mini = numeric_limits<int>::max();
        int ptr = -1;
        for (int i = pos + 1; i < n; i++) {
             if (nums[i] > nums[pos] && nums[i] <= mini) {
                 mini = nums[i];
                 ptr = i;
             }
        }
        swap(nums[pos], nums[ptr]);
        reverse(nums.begin() + pos + 1, nums.end());
    }
};
