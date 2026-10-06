class Solution(object):
    def colorBorder(self, grid, r0, c0, color):
        self.n = len(grid)
        self.m = len(grid[0])
        
        self.points = set()
        
        origin = grid[r0][c0]
        self.dfs(grid, r0, c0, grid[r0][c0], color)
        
        for (y, x) in self.points:
            cnt = 0
            for (my, mx) in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
                ny = y + my
                nx = x + mx
                if (ny, nx) in self.points:
                    cnt += 1

            if cnt != 4:
                grid[y][x] = color
            else:
                grid[y][x] = origin

        
        return grid
    
    def dfs(self, grid, y, x, color, rep):
        if color == rep:
            return
        
        if grid[y][x] != color:
            return
        
        self.points.add((y, x))
        
        grid[y][x] = '*'
        
        for (my, mx) in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            ny = y + my
            nx = x + mx
            
            if 0 <= ny < self.n and 0 <= nx < self.m and grid[ny][nx] == color:
                self.dfs(grid, ny, nx, color, rep)
