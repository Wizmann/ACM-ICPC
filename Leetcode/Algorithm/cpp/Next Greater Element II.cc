class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        map<int, int> mp1;
        multimap<int, int> mp2;
        
        
        int n = nums.size();
        
        if (n == 0) {
            return {};
        }
        
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            mp2.insert({cur, i});
        }
        
        vector<int> res(n, 0);
        
        int pre = mp2.rbegin()->first;
        vector<pair<int, int>> t;
        for (auto iter = mp2.rbegin(); iter != mp2.rend(); ++iter) {
            int value = iter->first;
            int pos = iter->second;
            
            if (value == pre) {
                t.push_back({pos, value});
            } else {
                for (auto p: t) {
                    mp1.insert(p);
                }
                t.clear();
                t.push_back({pos, value});
            }
            
            
            auto jter = mp1.lower_bound(pos);
            
            if (jter != mp1.end()) {
                res[pos] = jter->second;
            } else if (!mp1.empty() && mp1.begin()->first < pos) {
                res[pos] = mp1.begin()->second;
            } else {
                res[pos] = -1;
            }
            
            
            pre = value;
        }
        return res;
    }
};
