INF = 10 ** 10

class Solution(object):
    def __init__(self):
        self.d = {}

    def minInsertions(self, s):
        n = len(s)
        res = INF
        for i in xrange(n):
            res = min(res, self.solve(s, i, i + 1))
            res = min(res, self.solve(s, i - 1, i + 1))
        return res

    def solve(self, s, l, r):
        #print l, r
        key = (l, r)
        if key in self.d:
            return self.d[key]
        if l < 0 and r >= len(s):
            return 0
        lc, rc = '^', '$'
        if l >= 0:
            lc = s[l]
        if r < len(s):
            rc = s[r]

        res = INF
        if lc == rc:
            res = self.solve(s, l - 1, r + 1)
        else:
            if r < len(s):
                res = min(res, self.solve(s, l, r + 1) + 1)
            if l >= 0:
                res = min(res, self.solve(s, l - 1, r) + 1)
        self.d[key] = res
        return res


