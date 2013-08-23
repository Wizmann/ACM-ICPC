class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int sz = max(a.length(), b.length());
        int va, vb, g = 0;
        string c;
        for (int i = 0 ; i <= sz; i++) {
            if (i == sz && g == 0) {
                break;
            }
            if (i > a.length()) {
                va = 0; 
            } else {
                va = a[i] == '1';
            }
            
            if (i > b.length()) {
                vb = 0;
            } else {
                vb = b[i] == '1';
            }
            
            int v = va + vb + g;
            g = v / 2;
            v = v % 2;
            
            c += v? '1' : '0';
        }
        reverse(c.begin(), c.end());
        return c;
    }
};
