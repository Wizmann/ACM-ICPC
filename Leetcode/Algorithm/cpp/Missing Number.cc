class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == i) {
                continue;
            }
            while (nums[i] != i) {
                int a = nums[i];
                if (a == n) {
                    break;
                }
                if (nums[i] == nums[a]) {
                    break;
                }
                swap(nums[i], nums[a]);
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans = i;
                break;
            }
        }
        if (ans == -1) {
            ans = n;
        }
        return ans;
    }
};
