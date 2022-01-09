from collections import defaultdict

INF = 10 ** 10
MOD = 10 ** 9 + 7

class Solution(object):
    def countRestrictedPaths(self, n, edges):
        g = defaultdict(list)
        for (u, v, w) in edges:
            g[u].append((v, w))
            g[v].append((u, w))
            
        dis = [INF for i in xrange(n + 1)]
        visited = set([n])
        q = [n]
        dis[n] = 0
        while q:
            cur = q.pop(0)
            visited.remove(cur)
            for (v, w) in g[cur]:
                if dis[v] > dis[cur] + w:
                    dis[v] = dis[cur] + w
                    if v not in visited:
                        visited.add(v)
                        q.append(v)
        self.dp = [-1 for i in xrange(n + 1)]
        self.dis = dis
        self.dp[1] = 1
        self.g = g
        # print self.dis
        self.dfs(n)
        # print self.dp
        return self.dp[n]
    
    def dfs(self, cur):
        if self.dp[cur] != -1:
            return self.dp[cur]
        res = 0
        for (v, _) in self.g[cur]:
            if self.dis[v] > self.dis[cur]:
                res += self.dfs(v)
                res %= MOD
        res %= MOD
        self.dp[cur] = res
        return res
