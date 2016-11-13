class Solution {
public:
    string toHex(uint32_t num) {
        string ans = "";
        do {
            uint32_t x = num & 0xF;
            ans += "0123456789abcdef"[x];
            num >>= 4;
        } while (num != 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
