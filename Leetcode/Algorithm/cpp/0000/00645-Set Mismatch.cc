class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1) {
                if (nums[i] == nums[nums[i] - 1]) {
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);                
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return vector<int>{nums[i], i + 1};
            }
        }
        return vector<int>();
    }
};
