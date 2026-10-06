class Solution(object):
    def minTimeToVisitAllPoints(self, points):
        n = len(points)
        res = 0
        for i in xrange(1, n):
            dy = abs(points[i][0] - points[i - 1][0])
            dx = abs(points[i][1] - points[i - 1][1])
            
            res += max(dy, dx)
        return res
