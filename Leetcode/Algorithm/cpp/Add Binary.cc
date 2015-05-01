class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        int maxlen = max(a.length(), b.length());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0, g = 0; i < maxlen + 1; i++) {
            int u = i >= a.length() ? 0: a[i] - '0';
            int v = i >= b.length() ? 0: b[i] - '0';
            g += u + v;
            if (g || i != maxlen) {
                c = char('0' + (g & 1)) + c;
            }
            g >>= 1;
        }
        return c;
    }
};
