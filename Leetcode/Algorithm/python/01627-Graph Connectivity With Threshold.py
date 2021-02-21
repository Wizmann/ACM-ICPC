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
        
    def is_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        return fa == fb
        
class Solution(object):
    def areConnected(self, n, threshold, queries):
        ds = DisjointSet(n + 1)
        for i in xrange(threshold + 1, n + 1):
            a = i
            for j in xrange(2, INF):
                b = a * j
                if b > n:
                    break
                ds.make_union(a, b)
        return [ds.is_union(a, b) for (a, b) in queries]
            
