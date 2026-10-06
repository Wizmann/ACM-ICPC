class Solution(object):
    def countServers(self, grid):
        n = len(grid)
        m = len(grid[0])
        sy = [sum(line) for line in grid]
        sx = [sum([grid[i][j] for i in xrange(n)]) for j in xrange(m)]
        
        ans = 0
        for i in xrange(n):
            for j in xrange(m):
                if grid[i][j] and (sy[i] > 1 or sx[j] > 1):
                    ans += 1
        return ans
