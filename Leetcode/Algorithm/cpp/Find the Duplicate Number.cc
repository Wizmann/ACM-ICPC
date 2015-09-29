class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] - 1 != i) {
                int u = nums[i] - 1;
                if (u >= n) {
                    break;
                }
                if (nums[u] == nums[i]) {
                    break;
                }
                swap(nums[i], nums[u]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] - 1 != i) {
                return nums[i];
            }
        }
    }
};
