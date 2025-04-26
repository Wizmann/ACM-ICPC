from collections import defaultdict

class Solution(object):
    def countPairsOfConnectableServers(self, edges, signalSpeed):
        self.g = defaultdict(list)
        for e in edges:
            a, b, w = e
            self.g[a].append((b, w))
            self.g[b].append((a ,w))
        self.signalSpeed = signalSpeed
        n = len(edges) + 1
        ans = []
        for i in xrange(n):
            res = []
            for nxt, w in self.g[i]:
                u = self.dfs(nxt, i, w)
                if u:
                    res.append(u)
            m = len(res)
            u = 0
            tot = sum(res)
            if m >= 2:
                for i in xrange(m):
                    u += res[i] * (tot - res[i])
                    tot -= res[i]
            ans.append(u)
        return ans

    def dfs(self, cur, pre, depth):
        ret = 0
        if depth % self.signalSpeed == 0:
            ret += 1
        for nxt in self.g[cur]:
            b, e = nxt
            if b == pre:
                continue
            ret += self.dfs(b, cur, depth + e)
        return ret
