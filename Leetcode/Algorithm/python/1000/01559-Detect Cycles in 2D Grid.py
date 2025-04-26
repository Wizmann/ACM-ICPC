my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

class Solution(object):
    def containsCycle(self, grid):
        self.n = len(grid)
        self.m = len(grid[0])
        self.visited = [
            [False for j in xrange(self.m)]
            for i in xrange(self.n)]
        self.grid = grid
        
        for i in xrange(self.n):
            for j in xrange(self.m):
                if not self.visited[i][j]:
                    if self.dfs((-1, -1), (i, j), grid[i][j]):
                        return True
        return False
    
    def dfs(self, pre, cur, c):
        cy, cx = cur
        self.visited[cy][cx] = True
        for i in xrange(4):
            ny, nx = cy + my[i], cx + mx[i]
            if 0 <= ny < self.n and 0 <= nx < self.m and self.grid[ny][nx] == c:
                if (ny, nx) == pre:
                    continue
                if self.visited[ny][nx]:
                    return True
                if self.dfs(cur, (ny, nx), c):
                    return True
        return False
        
                    
