class Solution {
public:
    map<int, int> mp;
    int longestConsecutive(vector<int> &num) {
        mp.clear();
        int sz = num.size();
        
        for (int i = 0; i < sz; i++) {
            int v = num[i];
            if (mp.find(v) != mp.end()) {
                continue;
            }
            mp[v] = v;
            if (mp.find(v - 1) != mp.end()) {
                mp[v] = find_father(v - 1);
            }
            
            if (mp.find(v + 1) != mp.end()) {
                mp[v + 1] = find_father(v);
            }
        }
        
        map<int, int> summary;
        int ans = 0;
        for (map<int, int>::iterator iter = mp.begin();
                iter != mp.end();
                ++iter) {
            ++summary[find_father(iter->second)];
            ans = max(ans, summary[find_father(iter->second)]);
        }
        return ans;            
    }
    
    int find_father(int x)
    {
        if (mp[x] == x) {
            return x;
        } else {
            return mp[x] = find_father(mp[x]);
        }
    }
};
