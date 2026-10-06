class Solution(object):
    def findSmallestSetOfVertices(self, n, edges):
        ind = [0 for i in xrange(n)]
        self.g = [[] for i in xrange(n)]
        for (a, b) in edges:
            self.g[a].append(b)
            ind[b] += 1
        res = []

        for i, ind_ in enumerate(ind):
            if ind_ == 0:
                res.append(i)
        return res
        
            
