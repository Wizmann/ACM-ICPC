class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        
        vector<int> next;
        kmp_get_next(needle, next);
        
        int n = haystack.size();
        int m = needle.size();
        
        int i = 0;
        int j = 0;
        for (i = 0, j = 0; i < n && j < m; /* pass */) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        
        if (j == m) {
            return i - m;
        }
        return -1;
    }
private:
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
