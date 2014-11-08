class Solution {
public:
    char *strStr(char *heystack, char *needle) {
        int n = strlen(heystack);
        int m = strlen(needle);
        next = new int[m + 5];
        get_next(needle, m);

        int i, j;
        for (i = 0, j = 0; i < n && j < m; /* pass */) {
            if (j == -1 || heystack[i] == needle[j]) {
                i++; j++;
            } else {
                j = next[j];
            }
        }
        delete [] next;
        if (j == m) {
            return heystack + i - m;
        } else {
            return nullptr;
        }
    }
private:
    void get_next(char *needle, int n) {
        next[0] = -1;
        for (int pre = -1, suf = 0; suf < n; /* pass */) {
            if (pre == -1 || needle[pre] == needle[suf]) {
                pre++; suf++;
                next[suf] = pre;
            } else {
                pre = next[pre];
            }
        }
    }

    int* next;
};
