class Solution {
public:
    string shortestPalindrome(string s) {
        string ss = s;
        reverse(ss.begin(), ss.end());
        string concat = s + "#" + ss;
        
        int n = s.size();
        vector<int> next(n * 2 + 2, -1);
        get_next(concat, next);
        
        int ans = n - next[n * 2 + 1];
        s = ss.substr(0, ans) + s;
        return s;
    }
private:
    void get_next(const string& s, vector<int>& next) {
        int n = s.size();
        fill(next.begin(), next.end(), -1);
        for (int prefix = -1, suffix = 0; suffix < n; /* pass */) {
            if (prefix == -1 || s[prefix] == s[suffix]) {
                prefix++;
                suffix++;
                next[suffix] = prefix;
            } else {
                prefix = next[prefix];
            }
        }
    }
};
