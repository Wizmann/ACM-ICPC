from collections import defaultdict

class Solution(object):
    def gardenNoAdj(self, N, paths):
        self.res = [0 for i in xrange(N + 1)]
        self.g = defaultdict(list)
        for (a, b) in paths:
            self.g[a].append(b)
            self.g[b].append(a)
        for i in xrange(1, N + 1):
            self.dfs(i)
        return self.res[1:]
    
    def dfs(self, cur):
        if self.res[cur]:
            return
        adj = set()
        for node in self.g[cur]:
            if self.res[node]:
                adj.add(self.res[node])
        for i in [1, 2, 3, 4]:
            if i not in adj:
                self.res[cur] = i
                break
        for node in self.g[cur]:
            self.dfs(node)
