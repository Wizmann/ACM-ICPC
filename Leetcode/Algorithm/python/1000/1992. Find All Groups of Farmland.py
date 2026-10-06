my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

class Solution(object):
    def findFarmland(self, land):
        self.n = len(land)
        self.m = len(land[0])
        
        res = []
        for i in xrange(self.n):
            for j in xrange(self.m):
                if land[i][j] == 0:
                    continue
                r1, c1 = i, j
                r2, c2 = self.dfs(land, i, j)
                res.append((r1, c1, r2, c2))
        return res
    
    def dfs(self, land, y, x):
        r2, c2 = y, x
        land[y][x] = 0
        for i in xrange(4):
            ny = y + my[i]
            nx = x + mx[i]
            
            if 0 <= ny < self.n and 0 <= nx < self.m and land[ny][nx] == 1:
                r3, c3 = self.dfs(land, ny, nx)
                if r3 >= r2 and c3 >= c2:
                    r2, c2 = r3, c3
        return (r2, c2)
                
