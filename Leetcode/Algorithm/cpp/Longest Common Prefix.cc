class Solution {
public:
    static const int INF = 1<<28;
    string longestCommonPrefix(vector<string> &strs) {
        int sz = strs.size();
        if (sz == 0) {
            return string("");
        }
        
        int p = INF;
        for (int i = 1; i < sz; i++) {
            p = common_prefix(strs[0], strs[i], p);
        }
        return strs[0].substr(0, p);
    }
    
    int common_prefix(const string& a, const string& b ,int p)
    {
        int sz = min(a.size(), b.size());
        for (int i = 0; i < p && i < sz; i++)
        {
            if (a[i] != b[i]) {
                return i;
            }
        }
        return min(p, sz);
    }
};
