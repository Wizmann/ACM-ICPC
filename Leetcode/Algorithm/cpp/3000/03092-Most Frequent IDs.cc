typedef long long llint;

class Solution {
public:
    vector<llint> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, llint> mp;
        set<pair<llint, int> > st;
        int n = nums.size();
        vector<llint> res;
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i]) == 0) {
                mp[nums[i]] = 0;
                st.insert({0, nums[i]});
            }
            pair<llint, int> prev = {mp[nums[i]], nums[i]};
            st.erase(st.find(prev));
            mp[nums[i]] += freq[i];
            pair<llint, int> nxt = {mp[nums[i]], nums[i]};
            st.insert(nxt);
            res.push_back(st.rbegin()->first);
        }
        return res;
    }
};
