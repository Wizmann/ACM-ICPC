import math
from collections import defaultdict

INF = 10 ** 10

class Solution(object):
    def maxProbability(self, n, edges, succProb, start, end):
        succProb = map(lambda x: -math.log(x), succProb)
        g = defaultdict(list)
        for i, (a, b) in enumerate(edges):
            g[a].append((b, succProb[i]))
            g[b].append((a, succProb[i]))
        q = [start]
        visited = set([start])
        dis = [INF for i in xrange(n)]
        dis[start] = 0
        
        while q:
            # print dis
            cur = q.pop(0)
            visited.remove(cur)
            for (nxt, p) in g[cur]:
                if dis[nxt] > dis[cur] + p:
                    dis[nxt] = dis[cur] + p
                    if nxt not in visited:
                        q.append(nxt)
                        visited.add(nxt)
        if dis[end] == INF:
            return 0
        return 1.0 / math.exp(dis[end])
        
