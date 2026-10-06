INF = 10 ** 10

class DisjointSet(object):
    def __init__(self, n):
        self.father = range(n + 1)
    
    def find_father(self, x):
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
    def maxNumEdgesToRemove(self, n, edges):
        es = [[], [], []]
        for (t, a, b) in edges:
            es[t - 1].append((a, b))
        res = self.solve1(n, es[2]) + self.solve2(n, es[2], es[0]) + self.solve2(n, es[2], es[1])
        if res < 0:
            return -1
        return res
    
    def solve1(self, n, e1):
        ds = DisjointSet(n)
        res = 0
        for (a, b) in e1:
            if ds.check_union(a, b):
                res += 1
                continue
            ds.make_union(a, b)
        return res        
    
    def solve2(self, n, e1, e2):
        ds = DisjointSet(n)
        for (a, b) in e1:
            ds.make_union(a, b)
        
        res = 0
        for (a, b) in e2:
            if ds.check_union(a, b):
                continue
            #print a, b
            ds.make_union(a, b)
            res += 1
        #print '--'
        for i in xrange(2, n + 1):
            if not ds.check_union(1, i):
                return -INF
        return len(e2) - res
