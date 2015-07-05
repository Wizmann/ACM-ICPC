class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        // 123.456 e 789.012
        // ^         ^
        // bool a    bool b
        bool a = false;
        bool b = false;
        s = strip(s);
        auto idx_e = s.find("e");
        if (idx_e == string::npos) {
            b = true;
            a = detect_float(s);
        } else {
            b = detect_float(s.substr(idx_e + 1));
            a = detect_float(s.substr(0, idx_e));
        }
        return a && b;
    }
private:
    string strip(const string& s) {
        string res;
        for (auto c: s) {
            if (isspace(c)) {
                continue;
            }
            res += c;
        }
        return res;
    }
    bool detect_float(const string& s) {
        // 123.456
        // ^   ^
        // a   b
        auto idx_dot = s.find(".");
        bool a = false;
        bool b = false;
        
        if (idx_dot == string::npos) {
            b = true;
            a = detect_int(s, false);
        } else {
            b = detect_int(s.substr(idx_dot + 1));
            a = detect_int(s.substr(0, idx_dot), true);
        }
        return a && b;
    }
    
    bool detect_int(const string& s, bool empty=false) {
        if (s.empty()) {
            return empty;
        }
        for (auto c: s) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }

};
