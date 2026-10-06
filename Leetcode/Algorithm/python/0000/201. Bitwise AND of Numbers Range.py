class Solution:
    # @param m, an integer
    # @param n, an integer
    # @return an integer
    def rangeBitwiseAnd(self, m, n):
        ans = 0
        p = 0
        while m and n:
            if (n & 1) and n == m:
                ans |= 1 << p
            p += 1
            n >>= 1
            m >>= 1
        return ans
