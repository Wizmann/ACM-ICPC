class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int, int> mp1;
        map<int, int> mp2;
        map<int, int> mp3;
        int n = findNums.size();
        int m = nums.size();
        
        for (int i = 0; i < n; i++) {
            mp1[findNums[i]] = i;
        }
        
        for (int i = 0; i < m; i++) {
            mp2[nums[i]] = i;
        }
        
        vector<int> res(n, 0);
        for (auto iter = mp2.rbegin(); iter != mp2.rend(); ++iter) {
            int value = iter->first;
            int pos = iter->second;
            
            if (mp1.count(value) != 0) {
                auto jter = mp3.upper_bound(pos);
                if (jter != mp3.end()) {
                    res[mp1[value]] = jter->second;
                } else {
                    res[mp1[value]] = -1;
                }
            }
            
            mp3.insert({pos, value});
        }
        return res;
    }
};
