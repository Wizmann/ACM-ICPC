INF = 10 ** 10

class DisjointSet(object):
    def __init__(self):
        self.d = {}
        
    def find_father(self, x):
        if self.d.get(x, x) == x:
            return x
        ff = self.find_father(self.d[x])
        self.d[x] = ff
        return ff
    
    def same_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        return fa == fb
    
    def make_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        self.d[fa] = fb

class Solution(object):
    def distanceLimitedPathsExist(self, n, edgeList, queries):
        edgeList.append((0, 0, INF))
        edgeList.sort(key=lambda (u, v, dis): dis)
        qs = []
        for i, (p, q, limit) in enumerate(queries):
            qs.append((i, p, q, limit))
        qs.sort(key=lambda (i, p, q, limit): limit)
        ans = [0 for i in xrange(len(qs))]
        ds = DisjointSet()
        
        ptr = 0
        for (u, v, dis) in edgeList:
            while ptr < len(qs) and qs[ptr][3] <= dis:
                idx, p, q, limit = qs[ptr]
                # print 'query', p, q
                ans[idx] = ds.same_union(p, q)
                ptr += 1
            # print 'make_union', u, v
            ds.make_union(u, v)
        return ans
                
        
        
