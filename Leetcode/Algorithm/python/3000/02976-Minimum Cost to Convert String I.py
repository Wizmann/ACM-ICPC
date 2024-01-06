ALPHA = 26
INF = 2 ** 60
xrange = range

class Solution(object):
    def minimumCost(self, source, target, original, changed, cost):
        g = [ [INF for i in xrange(ALPHA)] for j in xrange(ALPHA) ]
        
        for i in xrange(ALPHA):
            g[i][i] = 0

        m = len(cost)
        for i in xrange(m):
            a = ord(original[i]) - ord('a')
            b = ord(changed[i]) - ord('a')
            c = cost[i]
            g[a][b] = min(g[a][b], c)


        for i in xrange(ALPHA):
            for j in xrange(ALPHA):
                for k in xrange(ALPHA):
                    g[j][k] = min(g[j][k], g[j][i] + g[i][k])
        tot = 0
        for a, b in zip(source, target):
            a = ord(a) - ord('a')
            b = ord(b) - ord('a')
            tot += g[a][b]
            if tot >= INF:
                return -1
        return tot
