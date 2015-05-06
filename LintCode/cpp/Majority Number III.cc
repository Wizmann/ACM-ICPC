class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        int n = nums.size();
        while (true) {
            int faith = rand() % n;
            int num = nums[faith];
            int cnt = 0;
            
            for (auto v: nums) {
                if (v == num) {
                    cnt++;
                }
            }
            
            if (cnt > n / k) {
                return num;
            }
        }
        return -1;
    }
};

