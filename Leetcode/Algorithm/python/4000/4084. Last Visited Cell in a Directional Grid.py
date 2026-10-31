class Solution(object):
    def lastVisitedCell(self, grid):
        y, x = 0, 0
        n = len(grid)
        m = len(grid[0])
        mv = {
            'L': (0, -1),
            'R': (0, 1),
            'U': (-1, 0),
            'D': (1, 0),
        }
        py, px = -1, -1
        while y >= 0 and x >= 0 and y < n and x < m:
            if grid[y][x] == 'X':
                break
            dy, dx = mv[grid[y][x]]
            grid[y][x] = 'X'
            py, px = y, x
            y += dy
            x += dx
        return [py, px]
