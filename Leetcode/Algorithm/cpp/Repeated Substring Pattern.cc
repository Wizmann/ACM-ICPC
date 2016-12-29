class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        if (str.empty()) {
            return false;
        }
        int n = str.size();
        vector<int> next;
        kmp_get_next(str, next);
        int g = *next.rbegin();
        return g && n % (n - g) == 0;
    }
    
    void kmp_get_next(const string& needle, vector<int>& next) {
        int n = needle.size();
        next = vector<int>(n + 1, -1);
        for (int pre = -1, suf = 0; pre < n && suf < n; /* pass */) {
            if (pre == -1 || needle[pre] == needle[suf]) {
                pre++;
                suf++;
                next[suf] = pre;
            } else {
                pre = next[pre];
            }
        }
    }
};
