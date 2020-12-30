class Solution(object):
    def hasValidPath(self, grid):
        self.n = len(grid)
        self.m = len(grid[0])
        self.grid = grid
        return self.dfs(0, 0, set())
    
    def dfs(self, y, x, visited):
        # print y, x
        if y == self.n - 1 and x == self.m - 1:
            return True
        cur = y * self.m + x
        if cur in visited:
            return False
        visited.add(cur)
        g = self.grid[y][x]
        ps = [
                ([1, 4, 6], [1, 3, 5], (0, 1)),
                ([1, 3, 5], [1, 4, 6], (0, -1)),
                ([2, 5, 6], [2, 3, 4], (-1, 0)),
                ([2, 3, 4], [2, 5, 6], (1, 0)),
             ]
        for src, dest, (dy, dx) in ps:
            ny, nx = y + dy, x + dx
            if 0 <= ny < self.n and 0 <= nx < self.m and g in src and self.grid[ny][nx] in dest:
                if self.dfs(ny, nx, visited):
                    return True
        visited.remove(cur)
        return False
