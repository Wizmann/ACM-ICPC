INF = 10 ** 10

class Solution:
    """
    @param N: The number of buses
    @param route: The route of buses
    @param A: Start bus station
    @param B: End bus station
    @return: Return the minimum transfer number
    """
    def getMinTransferNumber(self, N, route, A, B):
        route = [ set([A]) ] + map(set, route) + [ set([B]) ]
        n = len(route)
        g = [ [] for i in xrange(n) ]
        
        for i in xrange(n):
            for j in xrange(n):
                if route[i] & route[j]:
                    g[i].append(j)
                    
        res = self.spfa(n, g)
        if res >= INF:
            return -1
        else:
            return res - 1
        
    def spfa(self, n, g):
        dis = [INF for i in xrange(n)]
        dis[0] = 0
        inq = [False for i in xrange(n)]
        q = [0]
        
        while q:
            cur = q.pop(0)
            inq[cur] = False
            
            for next in g[cur]:
                if dis[next] > dis[cur] + 1:
                    dis[next] = dis[cur] + 1
                    if not inq[next]:
                        inq[next] = True
                        q.append(next)
        return dis[n - 1]
        
