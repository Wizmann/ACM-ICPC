MOD = 1337

def mypow(a, b, c):
    res = 1
    while b:
        if b & 1:
            res = (res * a) % MOD
        a = (a * a) % MOD
        b >>= 1
    return res

class Solution(object):
    def superPow(self, a, b):
        base = a
        res = 1
        for item in b[::-1]:
            y = mypow(base, item, MOD)
            res = (res * y) % MOD
            base = mypow(base, 10, MOD)
        return res
