class Solution {
    typedef long long llint;
public:
    int arrangeCoins(int n) {
        int l = 0;
        int r = n;
        while (l <= r) {
            int m = (l + r + 0LL) >> 1;
            llint u = sumup(m);
            if (u > n) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
private:
    llint sumup(int x) {
        return 1LL * (1 + x) * x / 2;
    }
};
