MOD = (1 << 61) - 1
ALPHA = 29
MAXN = 123456

pows = [1]
for i in xrange(1, MAXN):
    pows.append(pows[i - 1] * ALPHA % MOD)

class Solution(object):
    def minStartingIndex(self, s, pattern):
        h = 0
        m = len(pattern)
        for i in xrange(m):
            h = (h * ALPHA + ord(pattern[i]) - ord('a') + 1) % MOD
        chars = set(s)
        st = set([h])
        for i in xrange(m):
            for c in chars:
                hh = h
                hh -= (ord(pattern[i]) - ord('a') + 1) * pows[m - 1 - i]
                hh += (ord(c) - ord('a') + 1) * pows[m - 1 - i]
                hh = ((hh % MOD) + MOD) % MOD
                st.add(hh)
        n = len(s)
        h = 0
        for i in xrange(n):
            h = (h * ALPHA + ord(s[i]) - ord('a') + 1) % MOD
            if i - m >= 0:
                h -= (ord(s[i - m]) - ord('a') + 1) * pows[m]
                h = ((h % MOD) + MOD) % MOD
            if h in st:
                return i - m + 1
        return -1
