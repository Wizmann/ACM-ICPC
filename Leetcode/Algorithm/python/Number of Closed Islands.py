from collections import defaultdict

my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

class Solution(object):
    def closedIsland(self, grid):
        n = len(grid)
        m = len(grid[0])
        self.n = n
        self.m = m
        
        self.d = defaultdict(list)
        
        idx = 10
        for i in xrange(n):
            for j in xrange(m):
                if grid[i][j] == 0:
                    self.dfs(grid, i, j, idx)
                    idx += 1
        res = 0
        #print self.d
        for (_, lands) in self.d.items():
            flag = True
            for (y, x) in lands:
                for i in xrange(4):
                    ny = y + my[i]
                    nx = x + mx[i]
                    if not self.inMap(ny, nx):
                        flag = False
                        break
                if not flag:
                    break
            if flag:
                res += 1
        return res
    
    def inMap(self, y, x):
        return 0 <= y < self.n and 0 <= x < self.m
    
    def dfs(self, grid, y, x, idx):
        assert grid[y][x] == 0
        self.d[idx].append((y, x))
        grid[y][x] = idx
        for i in xrange(4):
            ny = y + my[i]
            nx = x + mx[i]
            
            if self.inMap(ny, nx) and grid[ny][nx] == 0:
                self.dfs(grid, ny, nx, idx)
