MOD = (10 ** 9) + 7

class Solution(object):
    def sumSubseqWidths(self, A):
        n = len(A)
        A.sort()
        l, r = 0, 0
        for i in xrange(n):
            l += A[i] * (1 << i)
            r += A[i] * (1 << (n - i - 1))
            r %= MOD
            l %= MOD
        return ((l - r) % MOD + MOD) % MOD
