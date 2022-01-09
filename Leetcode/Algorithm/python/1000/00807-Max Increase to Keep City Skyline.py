class Solution(object):
    def maxIncreaseKeepingSkyline(self, grid):
        n = len(grid)
        m = len(grid[0])
        
        ys = [max(line) for line in grid]
        xs = [max([grid[i][j] for i in xrange(n)]) for j in xrange(m)]
        
        res = 0
        for i in xrange(n):
            for j in xrange(m):
                u = grid[i][j]
                v = min(ys[i], xs[j])
                
                res += v - u
        return res
