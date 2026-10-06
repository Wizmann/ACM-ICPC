from collections import defaultdict

INF = 10 ** 100

class Solution(object):
    def mostProfitablePath(self, edges, bob, amount):
        n = len(amount)
        self.amount = amount
        self.depth = [0 for i in xrange(n)]
        self.father = [-1 for i in xrange(n)]
        self.g = defaultdict(list)
        for (a, b) in edges:
            self.g[a].append(b)
            self.g[b].append(a)

        self.dfs1(-1, 0, 0)

        dd = self.depth[bob]
        for i in xrange((dd + 1) / 2):
            self.amount[bob] = 0
            bob = self.father[bob]
        if dd % 2 == 0:
            self.amount[bob] /= 2
        # print self.amount
        # print self.g
        return self.dfs2(-1, 0)

    def dfs1(self, pre, cur, d):
        self.depth[cur] = d
        self.father[cur] = pre
        for nxt in self.g[cur]:
            if nxt == pre:
                continue
            self.dfs1(cur, nxt, d + 1)
    
    def dfs2(self, pre, cur):
        maxi = -INF
        if len(self.g[cur]) == 1 and self.g[cur][0] == pre:
            maxi = 0
        for nxt in self.g[cur]:
            if nxt == pre:
                continue
            maxi = max(maxi, self.dfs2(cur, nxt))
        return maxi + self.amount[cur]
