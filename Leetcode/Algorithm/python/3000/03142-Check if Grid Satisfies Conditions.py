class Solution(object):
    def satisfiesConditions(self, grid):
        n = len(grid)
        m = len(grid[0])

        for i in xrange(n):
            for j in xrange(m):
                if ((i + 1 >= n or grid[i][j] == grid[i + 1][j]) and 
                    (j + 1 >= m or grid[i][j] != grid[i][j + 1])):
                    pass
                else:
                    return False
        return True
