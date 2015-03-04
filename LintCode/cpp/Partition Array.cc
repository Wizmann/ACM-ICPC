class Solution {
public:
    int partitionArray(vector<int> &nums, int pivot) {
        int n = nums.size();
        
        if (n == 0) {
            return 0;
        }
        
        int l = 0;
        int r = n - 1;

        while (l < r) {
            while (l < r && nums[l] < pivot) {
                l++;
            }
            while (l < r && nums[r] >= pivot) {
                r--;
            }
            if (l < r) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
        if (nums[l] < pivot) {
            l++;
        }
        return l;
    }
};


