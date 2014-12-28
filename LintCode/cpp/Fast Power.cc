class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        a %= b;
        if (n == 0) {
            return 1 % b;
        }
        if (n == 1) {
            return a % b;
        }
        long long ans = 1;
        long long u = fastPower(a, b, n / 2);
        if (n & 1) {
            ans = (u * u) % b * a % b;
        } else {
            ans = u * u % b;
        }
        return ans;
    }
};
