class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        int n = nums.size();
        bool flag = false;
        
        for (int i = n - 2; i >= 0; i--) {
            int a = nums[i];
            int b = nums[i + 1];
            
            if (a > b) {
                int c = numeric_limits<int>::min();
                int p = -1;
                for (int j = n - 1; j > i; j--) {
                    if (nums[j] < a && nums[j] > c) {
                        p = j;
                        c = nums[j];
                    }
                }
                swap(nums[i], nums[p]);
                reverse(nums.begin() + i + 1, nums.begin() + n);
                flag = true;
                break;
            }
        }
        
        if (!flag) {
            reverse(nums.begin(), nums.begin() + n);
        }
        return nums;
    }
};
