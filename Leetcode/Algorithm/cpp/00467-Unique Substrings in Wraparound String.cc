class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int l = 0;
        int r = 0;
        int n = p.size();
        mp.clear();
        
        for (int i = 1; i <= n; i++) {
            if (i == n) {
                calc(p, l, r);
                break;
            }
            int a = p[i - 1] - 'a';
            int b = p[i] - 'a';

            if ((a + 1) % 26 == b) {
                r = i;
            } else {
                calc(p, l, r);
                l = r = i;
            }
        }
        
        int ans = 0;
        for (auto p: mp) {
            int len = p.second;
            ans += len;
        }
        return ans;
    }
private:
    void calc(const string& p, int l, int r) {
        for (int i = l; i <= r; i++) {
            char c = p[i];
            int len = r - i + 1;
            mp[c] = max(mp[c], len);
        }
    }
private:
    map<char, int> mp;
};
