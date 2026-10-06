from collections import defaultdict

class Solution(object):
    def oddCells(self, n, m, indices):
        rs = defaultdict(int)
        cs = defaultdict(int)
        
        for (y, x) in indices:
            rs[y] += 1
            cs[x] += 1
        
        mat = [ (rs[i] + cs[j]) % 2 for j in xrange(m) for i in xrange(n) ] 
        return sum(mat)
