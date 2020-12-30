class Solution {
public:
    int compress(vector<char>& chars) {
        int p = 0;
        int q = 0;
        const int n = chars.size();
        
        while (p < n && q < n) {
            int r = q;
            while (r < n && chars[r] == chars[q]) {
                r++;
            }
            int count = r - q;
            chars[p] = chars[q];
            p++;
            q = r;
            
            if (count >= 2) {
                string s = to_string(count);
                for (char c: s) {
                    chars[p] = c;
                    p++;
                }
            }
        }
        return p;
    }
};
