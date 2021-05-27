INF = 10 ** 10

class Solution(object):
    def stoneGameVIII(self, stones):
        n = len(stones)
        pre = sum(stones)

        maxi = -INF
        for i in xrange(n - 1, 0, -1):
            maxi = max(maxi, pre - (0 if i + 1 == n else maxi))
            pre -= stones[i]
        return maxi
