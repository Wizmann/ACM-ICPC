class Solution {
public:
    int longestWPI(vector<int>& hours) {
        map<int, int> mp;
        mp[0] = -1;
        int pre = 0;
        int n = hours.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int h = hours[i];
            h = h > 8? 1 : -1;
            pre += h;
            
            if (pre > 0) {
                res = max(res, i + 1);
            }
            
            auto iter = mp.find(pre - 1);
            if (iter != mp.end()) {
                res = max(res, i - iter->second);
            }
            
            if (mp.count(pre) == 0) {
                mp[pre] = i;
            }
        }
        return res;
    }
};
