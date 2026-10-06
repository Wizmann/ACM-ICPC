class Solution(object):
    def findBall(self, grid):
        n = len(grid)
        m = len(grid[0])
        
        res = []
        for i in xrange(m):
            res.append(self.solve(i, grid))
        return res
        
    def solve(self, pos, grid):
        n = len(grid)
        m = len(grid[0])

        
        y, x = 0, pos
        for i in xrange(n):
            if grid[y][x] == 1:
                if x + 1 >= m:
                    return -1
                if grid[y][x + 1] == -1:
                    return -1
                y += 1
                x += 1
            else:
                if x - 1 < 0:
                    return -1
                if grid[y][x - 1] == 1:
                    return -1
                y += 1
                x -= 1
            if x < 0 or x >= m:
                return -1
        return x
