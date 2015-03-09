class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        int n = nums.size();
        int ans = 0x3f3f3f3f;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            int p = i + 1;
            int q = n - 1;
            
            while (p < q) {
                int s = nums[i] + nums[p] + nums[q];
                if (abs(ans - target) > abs(target - s)) {
                    ans = s;
                }
                if (s >= target) {
                    q--;
                } else {
                    p++;
                }
            }
        }
        return ans;
    }
};

