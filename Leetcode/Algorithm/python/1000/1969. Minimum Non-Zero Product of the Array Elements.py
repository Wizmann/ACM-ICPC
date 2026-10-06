MOD = (10 ** 9) + 7

class Solution(object):
    def minNonZeroProduct(self, p):
        res = (1 << p) - 1
        res *= pow((1 << p) - 2, ((1 << p) - 1) / 2, MOD)
        return res % MOD
