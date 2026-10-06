class Solution(object):
    def numWays(self, n, k):
        if n == 0:
            return 0
        a, b = k, 0
        for i in xrange(1, n):
            a, b = a * (k - 1) + b * (k - 1), a
        return a + b
