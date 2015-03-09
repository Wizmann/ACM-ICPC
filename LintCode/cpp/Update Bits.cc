class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        int mask = ((1ULL << (j + 1)) - 1) ^ ((1 << i) - 1);
        n &= ~mask;
        n |= m << i;
        return n;
    }
};
