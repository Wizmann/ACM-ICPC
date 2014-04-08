// The answer to that is that if you need more 
// than 3 levels of indentation, you're screwed 
// anyway, and should fix your program.
class Solution {
public:
    void reverseWords(string &s) {
        trim(s);
        reverse(s. begin(), s.end());
        size_t len = s.length();
        for (size_t i = 0, pre = 0; i <= len; i++) {
            if (isspace(s[i]) || i == len) {
                reverse(s.begin() + pre, s.begin() + i);
                pre = i + 1;
            }
        }
    }
    
    void trim(string &s) {
        size_t len = s.length();
        int p = 0, token = 0;
        for (size_t i = 0; i < len; i++) {
            if (isspace(s[i])) {
                token = 0;
                continue;
            }
            if (!token && p) {
                s[p++] = ' ';
            }
            s[p++] = s[i];
            token++;
        }
        s.erase(p, len);
    }
};

////////////////////////////////////////////////////////////

class Solution {
public:
    void reverseWords(string &s)
    {
        string token;
        istringstream iss(s);
        s = "";
        while (getline(iss, token, ' ')) {
            if (token.empty()) {
                continue;
            }
            s = token + (s.empty()? "":" ") + s;
        }
    }
};
