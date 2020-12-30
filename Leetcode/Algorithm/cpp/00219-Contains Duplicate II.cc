class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = numeric_limits<int>::max();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int u = nums[i];
            if (mp.find(u) != mp.end()) {
                ans = min(ans, i - mp[u]);
            }
            mp[u] = i;
        }
        return ans <= k;
    }
};
