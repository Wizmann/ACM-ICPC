class DisjointSet(object):
    def __init__(self, n):
        self.father = [i for i in xrange(n)]
        
    def make_union(self, *args):
        f = self.find_father(args[0])
        for u in args[1:]:
            self.father[self.find_father(u)] = f
    
    def find_father(self, x):
        if self.father[x] == x:
            return x
        self.father[x] = self.find_father(self.father[x])
        return self.father[x]
    
    def union_num(self):
        s = set()
        for i in xrange(len(self.father)):
            s.add(self.find_father(i))
        return len(s)

class Solution(object):
    def regionsBySlashes(self, grid):
        n = len(grid)
        if n == 0:
            return 0
        m = len(grid[0])
        if m == 0:
            return 0
        
        ds = DisjointSet(n * (m + 1) * 2 + m + 1)
        
        for i in xrange(n):
            for j in xrange(m):
                c = grid[i][j]
                b1 = i * (m + 1) * 2
                b2 = i * (m + 1) * 2 + m + 1
                b3 = i * (m + 1) * 2 + 2 *(m + 1)
                u = [b1 + j, b2 + j + 1, b3 + j, b2 + j]
                #print u
                if c == ' ':
                    ds.make_union(*u)
                elif c == '/':
                    ds.make_union(u[0], u[3])
                    ds.make_union(u[1], u[2])
                elif c == '\\':
                    ds.make_union(u[0], u[1])
                    ds.make_union(u[2], u[3])
                else:
                    assert False
        return ds.union_num() - n - 1
