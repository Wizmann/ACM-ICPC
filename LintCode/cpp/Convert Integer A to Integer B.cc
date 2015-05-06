class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        unsigned c = a ^ b;
        int res = 0;
        while (c) {
            res += c & 1;
            c >>= 1;
        }
        return res;
    }
};
