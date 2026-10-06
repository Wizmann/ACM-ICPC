class Solution(object):
    def maxWidthOfVerticalArea(self, points):
        xs = sorted(map(lambda (x, y): x, points))
        n = len(xs)
        res = 0
        for i in xrange(n - 1):
            res = max(res, xs[i + 1] - xs[i])
        return res
