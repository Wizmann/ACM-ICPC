class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i && nums[i - 1] == nums[i]) {
                continue;
            }
            int p = i + 1;
            int q = n - 1;
            
            while (p < q) {
                int s = nums[i] + nums[p] + nums[q];
                if (s == 0) {
                    res.push_back({nums[i], nums[p], nums[q]});
                }
                if (s <= 0) {
                    do {
                        p++;
                    } while (p < q && nums[p - 1] == nums[p]);
                }
                if (s >= 0) {
                    do {
                        q--;
                    } while (p < q && nums[q + 1] == nums[q]);
                }
            }
        }
        return res;
    }
};

