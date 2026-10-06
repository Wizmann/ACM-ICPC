INF = 10 ** 100

class Solution(object):
    def minOperations(self, k):
        if k <= 1:
            return 0
        mini = INF
        for i in xrange(1, k + 1):
            cur = (k + i) / (i + 1) - 1 + i
            mini = min(mini, cur)
        return mini
