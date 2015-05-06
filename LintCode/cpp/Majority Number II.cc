class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
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
            
            if (cnt > n / 3) {
                return num;
            }
        }
        return -1;
    }
};

