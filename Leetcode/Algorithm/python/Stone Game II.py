INF = 10 ** 10

class Solution(object):
    def stoneGameII(self, piles):
        self.d = {}
        maxi = self.solve(1, 0, piles)
        return (sum(piles) + maxi) / 2
    
    def solve(self, m, p, piles):
        if p == len(piles):
            return 0
        # print m, p
        key = (m, p)
        if key in self.d:
            return self.d[key]
        
        maxi = -INF
        for i in xrange(1, 2 * m + 1):
            if p + i > len(piles):
                break
            t = sum(piles[p: p + i])
            t -= self.solve(max(m, i), p + i, piles)
            maxi = max(maxi, t)
        self.d[key] = maxi
        return maxi
