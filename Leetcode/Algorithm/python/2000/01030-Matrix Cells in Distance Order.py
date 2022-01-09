class Solution(object):
    def allCellsDistOrder(self, R, C, r0, c0):
        res = []
        for i in xrange(R):
            for j in xrange(C):
                res.append([i, j])
        return sorted(res, key=lambda (y, x): abs(y - r0) + abs(x - c0))
        
