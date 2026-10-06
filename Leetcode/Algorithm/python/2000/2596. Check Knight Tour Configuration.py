class Solution(object):
    def checkValidGrid(self, grid):
        n = len(grid)
        m = len(grid[0])
        if grid[0][0]:
            return False
        steps = [None for i in xrange(n * m)]

        for i in xrange(n):
            for j in xrange(m):
                u = grid[i][j]
                steps[u] = (i, j)
        for i in xrange(1, n * m):
            y0, x0 = steps[i - 1]
            y1, x1 = steps[i]

            dy = abs(y0 - y1)
            dx = abs(x0 - x1)
            print y0 - y1, x0 - x1
            if (dy, dx) not in [(1, 2), (2, 1)]:
                return False
        return True
