class Solution(object):
    def getMaximumGold(self, grid):
        n = len(grid)
        m = len(grid[0])
        self.n = n
        self.m = m
        self.grid = grid
        res = 0
        for i in xrange(n):
            for j in xrange(m):
                if self.grid[i][j] > 0:
                    res = max(res, self.dfs(i, j))
        return res
        
    def dfs(self, y, x):
        mx = [0, 1, 0, -1]
        my = [-1, 0, 1, 0]
        cur = self.grid[y][x]
        if cur <= 0:
            return 0
        self.grid[y][x] = -1
        res = 0
        for i in xrange(4):
            ny = y + my[i]
            nx = x + mx[i]
            
            if 0 <= ny < self.n and 0 <= nx < self.m:
                res = max(res, self.dfs(ny, nx))
        res += cur        
        self.grid[y][x] = cur
        return res
