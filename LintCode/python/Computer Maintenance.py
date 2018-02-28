INF = 10 ** 10

class Solution:
    """
    @param n: the rows of matrix
    @param m: the cols of matrix
    @param badcomputers: the bad computers 
    @return: The answer
    """
    def maintenance(self, n, m, bcs):
        g = [[] for i in xrange(1024)]
        
        for p in bcs:
            g[p.x].append(p.y) # the input format is wrong
            
        for i in xrange(n):
            g[i].sort()
            
        a, b = -1, INF
        for i in xrange(n):
            print a, b
            print g[i]
            a, b = min(a + 1 if not g[i] else a + 1 + g[i][-1] * 2, b + m), \
                   min(a + m, b + 1 if not g[i] else (m - g[i][0] - 1) * 2 + b + 1)
            
        return min(a, b)
