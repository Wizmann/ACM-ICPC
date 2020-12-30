class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        int p = 0;
        int q = 0;
        
        while (p <= n && q <= m) {
            if (s[p] == t[q]) {
                p++;
                q++;
            } else {
                if (m == n + 1) {
                    return s.substr(p) == t.substr(q + 1);
                } else if (n == m + 1) {
                    return s.substr(p + 1) == t.substr(q);
                } else if (n == m) {
                    return s.substr(p + 1) == t.substr(q + 1);
                } else {
                    return false;
                }
            }
        }
        
        return false;
    }
};
