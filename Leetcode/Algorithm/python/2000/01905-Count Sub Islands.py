my = [-1, 0, 1, 0]
mx = [0, 1, 0, -1]

class DisjointSet(object):
    def __init__(self):
        self.father = {}
        
    def find_father(self, x):
        if self.father.get(x, x) == x:
            return x
        ff = self.find_father(self.father[x])
        self.father[x] = ff
        return ff
    
    def make_union(self, x, y):
        fa = self.find_father(x)
        fb = self.find_father(y)
        self.father[fb] = fa
        
    def same_union(self, x, y):
        fa = self.find_father(x)
        fb = self.find_father(y)
        return fa == fb

class Solution(object):
    def countSubIslands(self, grid1, grid2):
        n = len(grid1)
        m = len(grid1[0])
        self.n = n
        self.m = m
        
        ds = DisjointSet()
        visited = set()
        for i in xrange(n):
            for j in xrange(m):
                self.dfs1(grid1, i, j, ds, visited, (i, j))
                
        res = 0
                
        for i in xrange(n):
            for j in xrange(m):
                if grid1[i][j] == 1 and grid2[i][j] == 1:
                    if self.dfs2(grid1, grid2, i, j, ds, (i, j)):
                        print i, j
                        res += 1
        return res
    
    def dfs1(self, grid1, y, x, ds, visited, fp):
        if (y, x) in visited:
            return
        if grid1[y][x] != 1:
            return
        
        visited.add((y, x))
        ds.make_union((y, x), fp)

        for i in xrange(4):
            ny = y + my[i]
            nx = x + mx[i]
            
            if 0 <= ny < self.n and 0 <= nx < self.m:
                self.dfs1(grid1, ny, nx, ds, visited, fp)
        
    def dfs2(self, grid1, grid2, y, x, ds, fp):
        if grid2[y][x] != 1:
            return 0
        grid2[y][x] = -1
        
        res = 1
        if not ds.same_union((y, x), fp):
            res = 0

        for i in xrange(4):
            ny = y + my[i]
            nx = x + mx[i]
            
            if 0 <= ny < self.n and 0 <= nx < self.m and grid2[ny][nx] == 1:
                res &= self.dfs2(grid1, grid2, ny, nx, ds, fp)
        return res
                        
