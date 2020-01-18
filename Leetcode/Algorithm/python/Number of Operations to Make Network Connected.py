class DisjointSet(object):
    def __init__(self, n):
        self.n = n
        self.father = range(n)
        
    def makeUnion(self, a, b):
        fa = self.findFather(a)
        fb = self.findFather(b)
        self.father[fb] = fa
        
    def findFather(self, x):
        if self.father[x] == x:
            return x
        f = self.findFather(self.father[x])
        self.father[x] = f
        return f

class Solution(object):
    def makeConnected(self, n, conn):
        if len(conn) < n - 1:
            return -1
        
        ds = DisjointSet(n)
        for (a, b) in conn:
            ds.makeUnion(a, b)
        st = set()
        for i in xrange(n):
            st.add(ds.findFather(i))
        return len(st) - 1
        
