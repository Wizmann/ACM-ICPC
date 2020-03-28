MOD = 0xdeadbeefdeadbeef

class Solution(object):
    def longestPrefix(self, s):
        n = len(s)
        l, r = 0, 0
        base = 1
        PRIME = 29
        res = ""
        for i in xrange(n):
            l = l * PRIME + (ord(s[i]) - ord('a') + 1)
            r = r + base * (ord(s[n - i - 1]) - ord('a') + 1)
            l %= MOD
            r %= MOD
            base = (base * PRIME) % MOD
            if l == r and i != n - 1:
                res = s[:i + 1]
        return res
            
