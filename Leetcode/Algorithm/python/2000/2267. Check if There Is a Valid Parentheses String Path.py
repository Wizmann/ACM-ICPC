class Solution(object):
    def hasValidPath(self, grid):
        self.d = {}
        self.grid = grid
        return self.dfs(0, 0, 0)
        
    def dfs(self, y, x, v):
        n = len(self.grid)
        m = len(self.grid[0])
        
        if v > 0:
            return False
        
        key = (y, x, v)
        if key in self.d:
            return self.d[key]

        
        if self.grid[y][x] == '(':
            v -= 1
        else:
            v -= -1
            
        res = False
        if x == m - 1 and y == n - 1:
            return v == 0
        if not res and y + 1 < n:
            res |= self.dfs(y + 1, x, v)
        if not res and x + 1 < m:
            res |= self.dfs(y, x + 1, v)
        
        self.d[key] = res
        return res
        
