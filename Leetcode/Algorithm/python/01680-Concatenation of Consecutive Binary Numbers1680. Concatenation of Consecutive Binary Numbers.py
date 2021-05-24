MOD = (10 ** 9) + 7

def lowbit(x):
    return (x) & (-x)

class Solution(object):
    def concatenatedBinary(self, n):
        res = 0
        bit = 0
        for i in xrange(1, n + 1):
            if lowbit(i) == i:
                bit += 1
            res = (res * pow(2, bit, MOD) + i) % MOD
        return res
