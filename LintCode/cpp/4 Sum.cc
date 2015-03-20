class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        int cnt = 0;
        unordered_multimap<int, pair<int, int> > mp;
        unordered_map<int, int> cntmp;
        set<vector<int> > st;
        
        for (const auto& num: nums) {
            cntmp[num]++;
        }
        
        nums.clear();
        for (auto& p: cntmp) {
            auto key = p.first;
            auto value = p.second;
            
            for (int i = 0; i < min(value, 4); i++) {
                nums.push_back(key);
            }
        }
        
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int s = nums[i] + nums[j];
                auto range = mp.equal_range(target - s);
                for (auto iter = range.first; iter != range.second; ++iter) {
                    if (overlap({i, j}, iter->second)) {
                        continue;
                    }
                    cnt++;
                    vector<int> tuple4({
                            nums[i], nums[j],
                            nums[iter->second.first], nums[iter->second.second]
                    });
                    sort(tuple4.begin(), tuple4.end());
                    st.insert(tuple4);
                }
                mp.insert({s, {i, j}});
            }
        }
        vector<vector<int> > res;
        copy(st.begin(), st.end(), back_inserter(res));
        return res;
    }
private:
    bool overlap(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first  == b.first  || 
               a.first  == b.second ||
               a.second == b.first  || 
               a.second == b.second;
    }
};
