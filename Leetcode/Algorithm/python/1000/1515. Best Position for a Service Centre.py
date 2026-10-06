from math import sqrt

class Solution(object):
    def getMinDistSum(self, positions):
        self.ps = positions
        return self.ternary_search(
            lambda x: self.ternary_search(lambda y: self.distanceSum((x, y)), 0., 100.), 0., 100.)
        
    def distanceSum(self, p):
        y, x = p
        tot = 0
        for point in self.ps:
            py, px = point
            tot += sqrt((py - y) ** 2 + (px - x) ** 2)
        return tot
        
    def ternary_search(self, f, low, high, tol=1e-6):
        while high - low > tol:
            m1 = low + (high - low) / 3
            m2 = high - (high - low) / 3
            if f(m1) < f(m2):
                high = m2
            else:
                low = m1
        return f(low)
