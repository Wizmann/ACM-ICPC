from copy import deepcopy
INF = 10 ** 10

my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

class Solution(object):
    def minPushBox(self, grid):
        self.n = len(grid)
        self.m = len(grid[0])
        
        self.dp = {}
        self.checkdp = {}
        
        B = (-1, -1)
        S = (-1, -1)
        for i in xrange(self.n):
            for j in xrange(self.m):
                if grid[i][j] == 'B':
                    B = (i, j)
                    grid[i][j] = '.'
                if grid[i][j] == 'S':
                    S = (i, j)
                    grid[i][j] = '.'
        self.grid = grid
        
        self.res = INF
        nxt = self.check(B, S)
        if nxt:
            pos, dir = nxt[0]
            self.res = min(self.res, self.dfs(pos, dir, 0))
            
        if self.res == INF:
            return -1
        else:
            return self.res
        
    def check(self, b, s):
        key = (b, s)
        if key in self.checkdp:
            dirs = self.checkdp[key]
            return [(b, d) for d in set(dirs)]
        grid = self.grid
        by, bx = b
        sy, sx = s
        grid[by][bx] = 'B'
        
        q = [(sy, sx)]
        visited = set()
        dirs = []
        while q:
            y, x = q.pop(0)
            
            if (y, x) in visited:
                continue
                
            visited.add((y, x))
            
            for i in xrange(4):
                ny = y + my[i]
                nx = x + mx[i]
                
                if ny < 0 or ny >= self.n or nx < 0 or nx >= self.m:
                    continue
                if grid[ny][nx] == '#':
                    continue
                if grid[ny][nx] == 'B':
                    dirs.append((i + 2) % 4)
                    continue
                    
                if (ny, nx) not in visited:
                    q.append((ny, nx))
            if len(dirs) == 4:
                break
        res = [(b, d) for d in set(dirs)]
        '''
        for line in grid:
            print ''.join(line)
        print res
        '''
        grid[by][bx] = '.'
        self.checkdp[key] = dirs
        return res
    
    def dfs(self, pos, d, step):
        key = (pos, d)
        #print key, step
        if key in self.dp and step >= self.dp[key]:
            return INF
        if step >= self.res:
            return INF
        self.dp[key] = step
        
        res = INF
        
        (by, bx) = pos
        
        if self.grid[by][bx] == 'T':
            self.res = min(self.res, step)
            return step
        
        (sy, sx) = by + my[d], bx + mx[d]
        nxt = self.check(pos, (sy, sx))
         
        for (_, nd) in nxt:
            kkey = (pos, nd)
            self.dp[kkey] = step
            dd = (nd + 2) % 4
            ny = by + my[dd]
            nx = bx + mx[dd]
            if ny < 0 or ny >= self.n or nx < 0 or nx >= self.m or self.grid[ny][nx] == '#':
                continue
            res = min(res, self.dfs((ny, nx), nd, step + 1))
        return res

