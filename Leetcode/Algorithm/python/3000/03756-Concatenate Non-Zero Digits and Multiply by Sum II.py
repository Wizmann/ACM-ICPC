MOD = (10 ** 9) + 7

class Solution(object):
    def sumAndMultiply(self, s, queries):
        s = [0] + map(int, s)
        n = len(s)

        pre1 = [0] * n
        for i in xrange(1, n):
            pre1[i] = (pre1[i - 1] + s[i]) % MOD

        pre2 = [0] * n
        pre3 = [0] * n
        acc = 0
        for i in xrange(1, n):
            if s[i]:
                acc = (acc * 10 + s[i]) % MOD
            pre2[i] = acc % MOD
            pre3[i] = pre3[i - 1] + (1 if s[i] else 0)
        
        res = []
        for (l, r) in queries:
            r += 1
            a = ((pre1[r] - pre1[l]) % MOD + MOD) % MOD
            b = pre2[r] - (pre2[l] * pow(10, pre3[r] - pre3[l], MOD)) % MOD
            b = (b % MOD + MOD) % MOD
            res.append(a * b % MOD)
        return res
