class Solution {
    typedef long long llint;
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<llint, int> mp;
        int n = nums.size();
        
        if (n == 0) {
            return false;
        }
        
        if (k == 0) {
            return false;
        }
        
        for (int i = 0; i < n; i++) {
            int pre = i - k - 1;
            if (pre >= 0) {
                llint bucket = nums[pre] / max(1, t);
                mp.erase(bucket);
            }
            
            int cur = nums[i];
            llint bucket = cur / max(1, t);
            
            for (int j = -1; j <= 1; j++) {
                if (mp.find(bucket + j) == mp.end()) {
                    continue;
                }
                int value = mp[bucket + j];
                if (abs(0LL + value - cur) <= t) {
                    cout << value << ' ' << cur << endl;
                    return true;
                }
            }
            mp[bucket] = cur;
        }
        return false;
    }
};
