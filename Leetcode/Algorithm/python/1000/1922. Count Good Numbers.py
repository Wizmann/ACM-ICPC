MOD = (10 ** 9) + 7

class Solution(object):
    def countGoodNumbers(self, n):
        odd = n / 2
        even = n - odd
        return pow(5, even, MOD) * pow(4, odd, MOD) % MOD
