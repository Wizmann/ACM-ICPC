class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
private:
    bool isMatch(const char* s, const char* p) {
        if (s == nullptr && p == nullptr) {
            return true;
        }
        // cout << int(*s) << ' ' << int(*p) << endl;
        if (*s == '\0' && *p == '\0') {
            return true;
        }
        
        if (mp.count({s, p}) != 0) {
            return mp[{s, p}];
        }
        
        if (*p && *(p + 1) == '*') {
            bool flag = false;
            const char* ss = s;
            while (*ss && (*p == '.' || *ss == *p)) {
                flag |= isMatch(ss + 1, p);
                ss++;
            }
            if (flag) {
                return mp[{s, p}] = true;
            }
            return mp[{s, p}] = isMatch(s, p + 2);
        } else if (*s) {
            if (*s == *p || *p == '.') {
                return mp[{s, p}] = isMatch(s + 1, p + 1);
            } else {
                return mp[{s, p}] = false;
            }
        } else {
            return mp[{s, p}] = false;
        }
    }
private:
    map<pair<const char*, const char*>, bool> mp;
};
