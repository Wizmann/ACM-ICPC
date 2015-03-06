class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        int n = nums.size();
        int p = 0, q = n - 1;
        for (int i = p; i <= q; /* pass */) {
            if (nums[i] == 0) {
                if (i == p) {
                    i++;
                    p++;
                } else {
                    swap(nums[i], nums[p]);
                    p++;
                }
            } else if (nums[i] == 2) {
                swap(nums[i], nums[q]);
                q--;
            } else {
                i++;
            }
        }
    }
};
