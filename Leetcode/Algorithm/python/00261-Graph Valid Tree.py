class DisjointSet(object):
    def __init__(self, n):
        self.n = n
        self.father = [i for i in xrange(n)]
        
    def make_union(self, a, b):
        self.father[self.find_father(a)] = self.find_father(b)
    
    def find_father(self, u):
        if self.father[u] == u:
            return u
        self.father[u] = self.find_father(self.father[u])
        return self.father[u]

class Solution(object):
    def validTree(self, n, edges):
        ds = DisjointSet(n)
        for (a, b) in edges:
            ds.make_union(a, b)
        s = set([ds.find_father(i) for i in xrange(n)])
        return len(s) == 1 and len(edges) == n - 1
        
