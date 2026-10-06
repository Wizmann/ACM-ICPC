from collections import defaultdict

INF = 10 ** 10

class DisjointSet(object):
    def __init__(self):
        self.father = {}
    
    def find_father(self, x):
        if x not in self.father:
            self.father[x] = x
        if self.father[x] == x:
            return x
        ff = self.find_father(self.father[x])
        self.father[x] = ff
        return ff
    
    def make_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        self.father[fa] = fb
        
    def check_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        return fa == fb

class Solution(object):
    def matrixRankTransform(self, matrix):
        n = len(matrix)
        m = len(matrix[0])
        self.matrix = matrix
        self.n = n
        self.m = m

        vs = defaultdict(list)

        for i in xrange(n):
            for j in xrange(m):
                vs[matrix[i][j]].append((i, j))
        
        self.miny = [0 for i in xrange(n)]
        self.minx = [0 for i in xrange(m)]
        res = [[-1 for j in xrange(m)] for i in xrange(n)]

        for v in sorted(vs.keys()):
            ds = DisjointSet()
            for (y, x) in vs[v]:
                ds.make_union(('y', y), ('x', x))
            groups = defaultdict(list)
            for (y, x) in vs[v]:
                groups[ds.find_father(('y', y))].append((y, x))

            for peers in groups.values():
                rank = max(
                        map(lambda peer: self.get_rank(peer), peers))
                # print v, rank, peers
                for (py, px) in peers:
                    res[py][px] = rank
                    self.miny[py] = rank
                    self.minx[px] = rank
        return res
    
    def get_rank(self, p):
        y, x = p
        return max(self.miny[y], self.minx[x]) + 1

    def get_index(self, y, x):
        return y * self.m + x
