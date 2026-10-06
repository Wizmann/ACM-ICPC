from collections import defaultdict

class Solution(object):
    def checkIfPrerequisite(self, n, prerequisites, queries):
        self.g = defaultdict(list)
        self.mark = [0 for i in xrange(n)]
        for (a, b) in prerequisites:
            self.g[a].append(b)
            
        for i in xrange(n):
            self.visited = [False for j in xrange(n)]
            self.dfs(i, 0)
        for (a, b) in queries:
            yield (self.mark[b] & (1 << a)) > 0
        
    def dfs(self, cur, pre):
        if self.visited[cur]:
            return
        self.visited[cur] = True
        self.mark[cur] |= pre
        pre |= 1 << cur
        for nxt in self.g[cur]:
            self.dfs(nxt, pre)
        
