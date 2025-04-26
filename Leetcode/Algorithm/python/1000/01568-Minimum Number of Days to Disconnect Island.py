INF = 10 ** 10
my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

class Solution(object):
    def minDays(self, grid):
        n = len(grid)
        m = len(grid[0])
        
        if self.check(grid):
            return 0
        
        ps = []
        for i in xrange(n):
            for j in xrange(m):
                cur = 0
                if grid[i][j] != 1:
                    continue
                for k in xrange(4):
                    ny = i + my[k]
                    nx = j + mx[k]
                    if 0 <= ny < n and 0 <= nx < m and grid[ny][nx] == 1:
                        cur += 1
                if grid[i] and cur <= 4:
                    ps.append((i, j))
        t = len(ps)            
        for i in xrange(t):
            i1, j1 = ps[i]
            assert grid[i1][j1] == 1
            grid[i1][j1] = 'x'
            if self.check(grid):
                return 1
            grid[i1][j1] = 1

        for i in xrange(t):
            i1, j1 = ps[i]
            grid[i1][j1] = 'x'
            for j in xrange(i + 1, t):
                i2, j2 = ps[j]
                grid[i2][j2] = 'y'
                if self.check(grid):
                    return 2
                grid[i2][j2] = 1
            grid[i1][j1] = 1
        return 3
    
    def check(self, grid):
        n = len(grid)
        m = len(grid[0])
        visit = [[0 for j in xrange(m)] for i in xrange(n)]
        idx = 0
        for i in xrange(n):
            for j in xrange(m):
                if grid[i][j] == 1 and visit[i][j] == 0:
                    idx += 1
                    if idx > 1:
                        break
                    self.check_(grid, visit, i, j, idx)
        return idx != 1
    
    def check_(self, grid, visit, y, x, idx):
        n = len(grid)
        m = len(grid[0])
        if grid[y][x] != 1 or visit[y][x] != 0:
            return
        visit[y][x] = idx
        for i in xrange(4):
            ny = y + my[i]
            nx = x + mx[i]
            if 0 <= ny < n and 0 <= nx < m:
                self.check_(grid, visit, ny, nx, idx)


