from collections import defaultdict

class Solution(object):
    def reachableNodes(self, n, edges, restricted):
        d = defaultdict(list)
        
        for (a, b) in edges:
            d[a].append(b)
            d[b].append(a)
        
        r = set(restricted)
        
        return self.dfs(-1, 0, d, r)
    
    def dfs(self, pre, cur, g, r):
        res = 1
        for nxt in g[cur]:
            if pre == nxt:
                continue
            if nxt in r:
                continue
            res += self.dfs(cur, nxt, g, r)
        return res
