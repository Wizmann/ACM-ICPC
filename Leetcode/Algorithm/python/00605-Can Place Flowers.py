class Solution(object):
    def canPlaceFlowers(self, flowerbed, m):
        flowerbed = [1, 0] + flowerbed + [0, 1]
        idx = map(lambda x: x[0], filter(lambda y: y[1], enumerate(flowerbed)))
        n = len(idx)
        ans = 0
        for i in xrange(n - 1):
            dis = idx[i + 1] - idx[i] - 1
            if dis >= 1:
                ans += (dis - 1) / 2
        print ans, m, idx
        return ans >= m
