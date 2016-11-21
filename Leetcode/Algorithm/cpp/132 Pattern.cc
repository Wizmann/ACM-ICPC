class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        int min_left = *nums.begin();
        multiset<int> rights;
        
        for (int i = 2; i < n; i++) {
            rights.insert(nums[i]);
        }
        
        for (int i = 1; i + 1 < n; i++) {
            auto iter = rights.upper_bound(min_left);
            if (iter != rights.end() && *iter < nums[i]) {
                return true;
            }
            rights.erase(rights.find(nums[i + 1]));
            min_left = min(min_left, nums[i]);
        }
        return false;
    }
};
