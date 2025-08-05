class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;
        nth_element(nums.begin(), nums.begin() + m, nums.end());
        int mid = *(nums.begin() + m);
        
        int i = 0;
        int j = 0;
        int k = n - 1;
        
        while (j <= k) {
            if (get_num(nums, j) > mid) {
                swap(get_num(nums, i++), get_num(nums, j++));
            } else if (get_num(nums, j) < mid) {
                swap(get_num(nums, j), get_num(nums, k--));
            } else {
                j++;
            }
        }
    }
private:
    int& get_num(vector<int>& nums, int i) {
        int p = (1 + 2 * i) % (nums.size() | 1);
        return nums[p];
    }
};
