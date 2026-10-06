class Solution(object):
    def minIncrements(self, n, cost):
        res = 0
        for i in xrange(n - 1, -1, -2):
            if i == 0:
                pass
            else:
                a, b = i - 1, i
                diff = abs(cost[a] - cost[b])
                res += diff
                cost[a / 2] += max(cost[a], cost[b])
        return res
