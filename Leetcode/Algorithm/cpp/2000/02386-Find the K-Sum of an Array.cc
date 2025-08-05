typedef long long llint;

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        const int n = nums.size();
        llint tot = 0;
        for (auto& num : nums) {
            if (num > 0) {
                tot += num;
            } else {
                num *= -1;
            }
        }
        sort(nums.begin(), nums.end());
        
        multimap<llint, int> mp;
        mp.insert({0, 0});
        llint res = 0;
        for (int i = 0; i < k; i++) {
            auto [cur, idx] = *mp.begin();
            res = tot - cur;
            // cout << res << endl;
            mp.erase(mp.begin());
            
            if (idx < n) {
                llint a = cur + nums[idx];
                mp.insert({a, idx + 1});
                if (idx - 1 >= 0) {
                    llint b = cur - nums[idx - 1] + nums[idx];
                    mp.insert({b, idx + 1});    
                }
            }
        }
        return res;
    }
};
