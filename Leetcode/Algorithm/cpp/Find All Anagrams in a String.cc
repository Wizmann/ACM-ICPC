class Solution {
    typedef long long llint;
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<int> ans;
        llint flag = 0;
        llint hash = 0;
        for (int i = 0; i < m; i++) {
            hash += to_hash(s[i]);
            flag += to_hash(p[i]);
        }
        
        for (int i = m; i <= n; i++) {
            if (hash == flag) {
                ans.push_back(i - m);
            }
            
            if (i == n) {
                break;
            }
            
            char pre = s[i - m];
            char now = s[i];
            
            hash -= to_hash(pre);
            hash += to_hash(now);
        }
        return ans;
    }
private:
    llint to_hash(char c) {
        llint t = 1LL << (c - 'a');
        return t * MAGIC; 
    }

    const int MAGIC = 21359;
};
