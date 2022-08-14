INF = 10 ** 10

class Solution(object):
    def closestMeetingNode(self, edges, node1, node2):
        n = len(edges)
        d1, d2 = {}, {}
        self.dfs(node1, edges, d1, 0, set())
        self.dfs(node2, edges, d2, 0, set())
        
        mini = -1
        minv = INF
        for i in xrange(n):
            v = max(d1.get(i, INF), d2.get(i, INF))
            if v < minv:
                minv = v
                mini = i
        return mini
    
    def dfs(self, cur, g, d, step, visited):
        if cur in visited:
            return
        d[cur] = step
        visited.add(cur)
        nxt = g[cur]
        if nxt != -1:
            self.dfs(nxt, g, d, step + 1, visited)
