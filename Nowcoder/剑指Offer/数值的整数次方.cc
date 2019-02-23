class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0) {
            return 1;
        }
        int g = exponent > 0? 1: -1;
        exponent = abs(exponent);
        double u = Power(base, exponent / 2);
        double res = u * u * (exponent % 2 == 0? 1: base);
        if (g == -1) {
            return 1.0 / res;
        }
        return res;
    }
};
