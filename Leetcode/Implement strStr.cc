class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int len_h = strlen(haystack);
        int len_n = strlen(needle);
        
        if (0 == len_n) {
            return haystack;
        }
        
        for (int i = 0; i < len_h; i++) {
            if (haystack[i] == needle[0]) {
                if (i + len_n > len_h) {
                    continue;
                } else {
                    bool flag = true;
                    for (int j = 0; j < len_n; j++) {
                        if (haystack[i+j] != needle[j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) return haystack + i;
                }
            }
        }
        return NULL;
    }
};
