class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string c;
        
        int aa = a.length();
        int bb = b.length();
        
        int g = 0;
        for (int i = 0; /* pass */; i++) {
            if (i >= aa && i >= bb && !g) {
                break;
            }
            int u = (i >= aa)? 0: a[i] - '0';
            int v = (i >= bb)? 0: b[i] - '0';
            
            int s = u + v + g;
            c += '0' + (s & 1);
            g = s >> 1;
        }
        reverse(c.begin(), c.end());
        return c;
    }
};
