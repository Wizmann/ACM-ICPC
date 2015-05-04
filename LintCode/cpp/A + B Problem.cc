class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        while (b) {
            int c = a & b;
            a ^= b;
            b = c << 1;
        }
        return a;
    }
};
