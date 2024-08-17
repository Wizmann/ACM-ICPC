class Solution(object):
    def minimumLevels(self, possible):
        possible = map(lambda x: -1 if x == 0 else 1, possible)
        tot = sum(possible)
        n = len(possible)
        cur = 0
        for i in xrange(n - 1):
            cur += possible[i]
            if tot - cur < cur:
                return i + 1
        return -1
