class Solution {
    typedef long long llint;

public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0 || t < 0) {
            return false;
        }
        
        multimap<int, pair<int, int>> mp;
        
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int u = nums[i] / max(1, t);
            for (int j = u - 1; j <= u + 1; j++) {
                auto p = mp.equal_range(j);
                for (auto iter = p.first; iter != p.second; ++iter) {
                    llint v = (iter->second).second;
                    if (abs(v - nums[i]) <= t) {
                        return true;
                    }
                }
            }
            mp.insert({u, {i, nums[i]}});
            if (i >= k) {
                auto iter = mp.lower_bound(nums[i - k] / max(1, t));
                mp.erase(iter);
            }
        }
        return false;
    }
};
