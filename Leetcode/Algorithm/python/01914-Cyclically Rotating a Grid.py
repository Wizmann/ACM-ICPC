class Solution(object):
    def rotateGrid(self, grid, k):
        n = len(grid)
        m = len(grid[0])
        
        for i in xrange(min(n, m) / 2):
            u = (n - i - i) * 2 + (m - i - i) * 2 - 4
            kk = k % u
            for j in xrange(kk):
                y, x = i, i
                y0, x0 = i, i
                y1, x1 = n - i - 1, m - i - 1

                cur = grid[y][x]
                while y + 1 <= y1:
                    cur, grid[y + 1][x] = grid[y + 1][x], cur
                    y += 1
                while x + 1 <= x1:
                    cur, grid[y][x + 1] = grid[y][x + 1], cur
                    x += 1
                while y - 1 >= y0:
                    cur, grid[y - 1][x] = grid[y - 1][x], cur
                    y -= 1
                while x - 1 >= x0:
                    cur, grid[y][x - 1] = grid[y][x - 1], cur
                    x -= 1
        return grid
                
