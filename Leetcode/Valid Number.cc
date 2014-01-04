class Solution {
public:
    bool isNumber(const char *s) {
        int len = strlen(s), la, lb, l;
        while (s[len - 1] == ' ') len--;
        while (*s == ' ') {
            s++; len--;
        }
        
        if (len <= 0) return false;

        for (int i = 0; i < len; i++) {
            if (s[i] == 'e') {
                int a = isFloat(s, i, la);
                int b = isInt(s + i + 1, len - i - 1, lb);

                if (la && lb && a != 0 && b != 0) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        
        int res = isFloat(s, len, l);
        return res != 0;
    }
    
    int isFloat(const char *s, int len, int& l) {
        for (int i = 0; i < len; i++) {
            if (s[i] == '.') {
                int la, lb;
                int a = isInt(s, i, la);
                int b = isInt(s + i + 1, len - i - 1, lb);
                
                if ((la || lb) && a != 0 && b == 1 && lb == len - i - 1) {
                    l = la + lb;
                    return 1;
                } else {
                    return 0;
                }
            }
        }
        return isInt(s, len, l);
    }
    
    int isInt(const char *s, int len, int& l) {
        int p = 0;
        int g = 1;
        if (s[p] == '-') {
            g = -1;
            p++;
        } else if (s[p] == '+') {
            g = 1;
            p++;
        }
        int num = 0;
        for (p; p < len; p++) {
            if (isdigit(s[p])) num++;
            else return 0;
        }
        l = num;
        return g;
    }
};
