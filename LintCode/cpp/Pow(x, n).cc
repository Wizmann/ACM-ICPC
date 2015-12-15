class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        if (n < 0) {
            return 1.0 / myPow(x, abs(n));
        }
        if (n == 0) {
            return 1;
        }
        double res = 1;
        if (n & 1) {
            res = x;
        }
        double y = myPow(x, n / 2);
        return res * y * y;
    }
};
