class Solution {
    typedef long long llint;
public:
    int reverse(int x) {
        int g = x > 0? 1: -1;
        llint y = 0;
        while (x) {
            y = y * 10 + abs(x % 10);
            x /= 10;
        }
        y *= g;
        if (y > numeric_limits<int>::max() || y < numeric_limits<int>::min()) {
            return 0;
        }
        return y;
    }
};
