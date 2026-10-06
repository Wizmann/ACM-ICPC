class Solution(object):
    def minCosts(self, cost):
        maxi = 10 ** 100
        res = []
        for c in cost:
            maxi = min(maxi, c)
            res.append(maxi)
        return res
