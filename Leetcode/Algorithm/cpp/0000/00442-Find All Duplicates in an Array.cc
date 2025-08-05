class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1) {
                if (nums[i] == nums[nums[i] - 1]) {
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        set<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                res.insert(nums[i]);
            }
        }
        vector<int> vec;
        copy(res.begin(), res.end(), back_inserter(vec));
        return vec;
    }
};
