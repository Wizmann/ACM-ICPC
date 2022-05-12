class Solution(object):
    def countUnguarded(self, n, m, guards, walls):
        g = [ [] for i in xrange(n) ]
        
        for (y, x) in guards:
            g[y].append((x, 0))
        for (y, x) in walls:
            g[y].append((x, 1))
            
        st1 = set()
        for i in xrange(n):
            g[i].append((-1, 1))
            g[i].append((m, 1))
            g[i].sort()
            
            u = len(g[i])
            
            for j in xrange(u - 1):
                p1, t1 = g[i][j]
                p2, t2 = g[i][j + 1]
                if t1 == 1 and t2 == 1:
                    for k in xrange(p1 + 1, p2):
                        st1.add((i, k))
                        
        g = [ [] for i in xrange(m) ]
        
        for (y, x) in guards:
            g[x].append((y, 0))
        for (y, x) in walls:
            g[x].append((y, 1))
            
        st2 = set()
        for i in xrange(m):
            g[i].append((-1, 1))
            g[i].append((n, 1))
            g[i].sort()
            
            u = len(g[i])
            
            for j in xrange(u - 1):
                p1, t1 = g[i][j]
                p2, t2 = g[i][j + 1]
                if t1 == 1 and t2 == 1:
                    for k in xrange(p1 + 1, p2):
                        st2.add((k, i))
                        
        # print st1, st2
                        
        return len(st1 & st2)
