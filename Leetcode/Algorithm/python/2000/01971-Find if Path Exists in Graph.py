from collections import defaultdict

class Solution(object):
    def validPath(self, n, edges, start, end):
        self.g = defaultdict(list)
        
        for (a, b) in edges:
            self.g[a].append(b)
            self.g[b].append(a)
            
        st = set()
        self.bfs(start, st)
        return end in st
    
    def bfs(self, cur, visited):
        if cur in visited:
            return
        visited.add(cur)
        for nxt in self.g[cur]:
            self.bfs(nxt, visited)
    
