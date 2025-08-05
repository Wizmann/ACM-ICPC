class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        int q = 0;
        
        while (p < n && q < n) {
            while (q < n && nums[q] == 0) {
                q++;
            }
            if (q < n) {
                swap(nums[p], nums[q]);
                p++;
                q++;
            }
        }
    }
};
