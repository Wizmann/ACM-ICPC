MOD = (10 ** 9) + 7

class Solution(object):
    def maxArea(self, h, w, hc, vc):
        hc += [0, h]
        vc += [0, w]
        hc.sort()
        vc.sort()
        return self.maxNeighbour(hc) * self.maxNeighbour(vc) % MOD
        
    def maxNeighbour(self, ns):
        maxi = -1
        n = len(ns)
        for i in xrange(n - 1):
            maxi = max(maxi, ns[i + 1] - ns[i])
        return maxi
