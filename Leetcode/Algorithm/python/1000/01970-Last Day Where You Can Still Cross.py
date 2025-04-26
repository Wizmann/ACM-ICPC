from collections import deque

mvs = [ (-1, 0), (0, 1), (1, 0), (0, -1), (-1, -1), (-1, 1), (1, -1), (1, 1) ]
INF = 10 ** 10

class DisjointSet(object):
    def __init__(self):
        self.father = {}
        
    def find_father(self, x):
        if x not in self.father:
            return (x, x[1], x[1])
        if x in self.father and self.father[x][0] == x:
            return self.father[x]
        f = self.find_father(self.father[x][0])
        self.father[x] = f
        return f
    
    def make_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        
        if fa != fb:
            fc = (fa[0], min(fa[1], fb[1]), max(fa[2], fb[2]))
            self.father[fa[0]] = fc
            self.father[fb[0]] = fc        

class Solution(object):
    def latestDayToCross(self, row, col, cells):
        n = len(cells)
        self.ds = DisjointSet()
        self.matrix = [ [0 for j in xrange(col)] for i in xrange(row) ]
        for i, cell in enumerate(cells):
            y, x = cell
            y -= 1
            x -= 1
            self.matrix[y][x] = 1
            if self.check(y, x):
                return i
        assert False
        return -1
    
    def check(self, y, x):
        n = len(self.matrix)
        m = len(self.matrix[0])

        for (dy, dx) in mvs:
            ny = y + dy
            nx = x + dx
            if 0 <= ny < n and 0 <= nx < m and self.matrix[ny][nx] == 1:
                self.ds.make_union((y, x), (ny, nx))
                _, mini, maxi = self.ds.find_father((y, x))
                # print y, x, ny, nx, mini, maxi
                if mini == 0 and maxi == m - 1:
                    return True
        return False
