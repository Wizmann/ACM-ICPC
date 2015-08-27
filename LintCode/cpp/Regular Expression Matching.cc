class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        if (*s == '\0' && *p == '\0') {
            return true;
        }
        if (*p == '\0') {
            return false;
        }
        
        bool res = false;
        if (!res && *(p + 1) == '*') {
            res |= isMatch(s, p + 2);
        }
        
        if (!res && *s && *p == '.' && *(p + 1) == '*') {
            res |= isMatch(s + 1, p);
        }
        
        if (!res && *p == *s && *(p + 1) == '*') {
            const char *ss = s;
            while (!res && *ss == *s) {
                res |= isMatch(ss + 1, p + 2);
                ss++;
            }
        }
        
        if (!res && (*p == '.' || *p == *s)) {
            res |= isMatch(s + 1, p + 1);
        }
        
        return res;
    }
};
