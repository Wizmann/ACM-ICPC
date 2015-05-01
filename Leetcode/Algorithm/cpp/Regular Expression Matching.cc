class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!(*s) && !(*p)) {
            return true;
        }

        if (*p && *(p+1) == '*') {
            int len = strlen(s);
            bool res = false;
            
            res |= isMatch(s, p+2);
            for (int i = 0; i < len && _match(*(s+i), *p); i++) {
                res |= isMatch(s + i + 1, p + 2);
            }
            return res;
        }
        
        if (_match(*s, *p)) {
            return isMatch(s+1, p+1);
        }
        
        return false;
    }

    inline bool _match(char s, char pattern)
    {
        if (!s) {
            return false;
        }
        if (pattern == s || pattern == '.') {
            return true;
        }
        return false;
    }
}; 
