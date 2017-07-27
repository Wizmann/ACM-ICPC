class Solution {
public:
    int countSubstrings(string s) {
        n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += expand(s, i - 1, i + 1) + 1;
            if (i + 1 < n && s[i] == s[i + 1]) {
                ans += expand(s, i - 1, i + 2) + 1;    
            }
        }
        return ans;
    }
private:
    int expand(const string& s, int l, int r) {
        int res = 0;
        while (l >= 0 && r < n && s[l] == s[r]) {
            res++;
            l--;
            r++;
        }
        return res;
    }
    
    int n;
};
