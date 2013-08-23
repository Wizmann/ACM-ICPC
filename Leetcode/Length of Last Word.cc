class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string str(s);
        reverse(str.begin(), str.end());
        int len = 0;
        for (int i = 0; i < str.length(); i++) {
            if (!len && str[i] == ' ') {
                continue;
            } else if (str[i] != ' ') {
                len++;
            } else {
                break;
            }
        }
        return len;
    }
};
