class Solution {
    typedef long long llint;
public:
    bool isPerfectSquare(int num) {
        llint l = 0;
        llint r = 0x3f3f3f3f;
        
        while (l <= r) {
            llint m = (l + r) >> 1;
            if (m * m > num) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r * r == num;
    }
};
