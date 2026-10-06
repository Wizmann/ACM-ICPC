from collections import defaultdict

class DisjointSet(object):
    def __init__(self, n):
        self.n = n
        self.father = range(n + 1)
    def find_father(self, x):
        if self.father[x] == x:
            return x
        f = self.find_father(self.father[x])
        self.father[x] = f
        return f
    
    def make_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        self.father[fa] = fb
        
    def same_set(self, a, b):
        return self.find_father(a) == self.find_father(b)

class Solution(object):
    def findCriticalAndPseudoCriticalEdges(self, n, edges):
        ds = DisjointSet(n)
        d = defaultdict(list)
        r1, r2 = [], []
        excludes = set()
        
        for i, (a, b, c) in enumerate(edges):
            d[c].append((i, a, b))
            
        for (cost, ee) in sorted(d.items()):
            for edge in ee:
                idx, a, b = edge
                fa, fb = ds.find_father(a), ds.find_father(b)
                if fa == fb:
                    excludes.add(idx)
            for edge in ee:
                idx, a, b = edge
                fa, fb = ds.find_father(a), ds.find_father(b)
                ds.make_union(fa, fb)
                
        edges = map(lambda (i, (a, b, c)): (i, a, b, c), enumerate(edges))
        edges.sort(key=lambda (i, a, b, c): c)
        
        m = len(edges)
        real_mst = self.get_mst(n, edges, set([]))
        for i in xrange(m):
            (idx, a, b, c) = edges[i]
            if idx in excludes:
                continue
            mst = self.get_mst(n, edges, set([idx]))
            if mst == real_mst:
                r2.append(idx)
            else:
                r1.append(idx)
                
        return r1, r2
    
    def get_mst(self, n, edges, excludes):
        ds = DisjointSet(n + 1)
        tot = 0
        for i, e in enumerate(edges):
            (idx, a, b, c) = e
            if idx in excludes:
                continue
            if ds.same_set(a, b):
                continue
            else:
                tot += c
                ds.make_union(a, b)
        return tot
