from collections import defaultdict

class Solution(object):
    def countSubstrings(self, s, t):
        n = len(s)
        m = len(t)

        res = 0
        for p1 in xrange(n):
            for p2 in xrange(m):
                l = min(n - p1, m - p2)
                diff = 0
                for i in xrange(l):
                    if s[p1 + i] != t[p2 + i]:
                        diff += 1
                    if diff == 1:
                        res += 1
                    elif diff > 1:
                        break
        return res

