class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int u = 1;
        int ans = 0;
        while (m && n) {
            if (m == n && (m & 1)) {
                ans |= u;
            }
            m >>= 1;
            n >>= 1;
            u <<= 1;
        }
        return ans;
    }
};
