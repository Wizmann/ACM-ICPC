class Solution(object):
    def countCornerRectangles(self, grid):
        n = len(grid)
        if n < 2:
            return 0
        m = len(grid[0])
        if m < 2:
            return 0
        
        d = [ set() for i in xrange(n) ]
        
        for i in xrange(n):
            d[i] = set([j for (j, v) in enumerate(grid[i]) if v == 1])
        
        res = 0
        for i in xrange(n):
            for j in xrange(i + 1, n):
                u = len(d[i] & d[j])
                res += u * (u - 1) / 2
                        
        return res
