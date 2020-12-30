class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        int u = 1;
        reverse(s.begin(), s.end());
        for (auto c: s) {
            int x = c - 'A' + 1;
            ans += x * u;
            u *= 26;
        }
        return ans;
    }
};
