class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (true) {
                int u = nums[i];
                if (u >= n || u < 0) {
                    break;
                }
                if (u == nums[u]) {
                    break;
                }
                swap(nums[u], nums[i]);
            }
        }
        int res = 0;
        while (res < n) {
            if (res != nums[res]) {
                break;
            }
            res++;
        }
        return res;
    }
};
