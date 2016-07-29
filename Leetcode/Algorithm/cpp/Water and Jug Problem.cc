class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x == z || y == z || x + y == z) {
            return true;
        }
        if (x + y < z || x * y == 0) {
            return false;
        }
        int g = gcd(x, y);
        return z % g == 0;
    }
private:
    int gcd(int a, int b) {
        if (a % b == 0) {
            return b;
        }
        return gcd(b, a % b);
    }
};
