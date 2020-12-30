INF = 0x3f3f3f3f

class Solution(object):
    def maxCount(self, n, m, ops):
        minx, miny = m, n 
        for (y, x) in ops:
            minx = min(minx, x)
            miny = min(miny, y)
        return minx * miny
