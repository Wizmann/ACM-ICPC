from collections import defaultdict
import string

MOD = 10 ** 9 + 7

class Solution(object):
    def uniqueLetterString(self, S):
        d = defaultdict(list)
        n = len(S)
        for i, c in enumerate(S):
            d[c].append(i)
        ans = 0
        for c in string.uppercase:
            m = len(d[c])
            for i in xrange(m):
                l, r = d[c][i] + 1, n - d[c][i]
                if i - 1 >= 0:
                    l = d[c][i] - d[c][i - 1]
                if i + 1 < m:
                    r = d[c][i + 1] - d[c][i]
                ans += l * r
                ans %= MOD
        return ans
