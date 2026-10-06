from collections import Counter

class Solution(object):
    def minimumHammingDistance(self, source, target, allowedSwaps):
        n = len(source)
        g = [ [] for i in xrange(n) ]
        
        for (a, b) in allowedSwaps:
            g[a].append(b)
            g[b].append(a)
            
        res = 0
        self.visited = [0 for i in xrange(n)]
        for i in xrange(n):
            if self.visited[i]:
                continue
            pos = []
            self.dfs(g, i, pos)
            c1 = Counter(map(lambda x: source[x], pos))
            c2 = Counter(map(lambda x: target[x], pos))
            for key, value in c1.items():
                res += min(value, c2[key])
        return n - res
    
    def dfs(self, g, cur, pos):
        if self.visited[cur]:
            return
        self.visited[cur] = 1
        pos.append(cur)
        for nxt in g[cur]:
            self.dfs(g, nxt, pos)
