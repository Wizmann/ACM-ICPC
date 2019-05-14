MOD = 0xdeadbeefdeadbeef

class Solution(object):
    def longestDupSubstring(self, S):
        self.S = S
        n = len(S)
        l, r = 1, n

        res = (-1, -1)
        while l <= r:
            m = (l + r) >> 1
            p, b = self.check(m)
            if b:
                res = max(res, (m, p))
                l = m + 1
            else:
                r = m - 1
        return S[res[1]: res[0] + res[1]]
    
    def check(self, m):
        s = set()
        h = 0
        for i in xrange(m):
            h = (h * 29 + ord(self.S[i]) - ord('a') + 1) % MOD
        s.add(h)
        pp = pow(29, m - 1, MOD)
        n = len(self.S)
        for i in xrange(m, n):
            h -= (ord(self.S[i - m]) - ord('a') + 1) * pp % MOD
            h = (h * 29 + ord(self.S[i]) - ord('a') + 1) % MOD
            if h in s:
                return i - m + 1, True
            s.add(h)
        return -1, False
