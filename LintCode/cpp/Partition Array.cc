class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        
        while (l <= r) {
            while (l <= r && nums[l] < k) { l++; }
            while (l <= r && nums[r] >= k) { r--; }
            if (l <= r) {
                swap(nums[l], nums[r]);
            }
        }
        return l;
    }
};
