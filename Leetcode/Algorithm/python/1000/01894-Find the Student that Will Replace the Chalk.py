INF = 10 ** 10

class Solution(object):
    def chalkReplacer(self, chalk, k):
        l, r = 0, INF
        n = len(chalk)
        for i in xrange(1, n):
            chalk[i] += chalk[i - 1]
        while l <= r:
            m = (l + r) / 2
            tot = (m / n) * chalk[-1] + (0 if m % n == 0 else chalk[m % n - 1])
            if tot > k:
                r = m - 1
            else:
                l = m + 1
        return r % n
