from collections import defaultdict
MOD = int(1e9 + 7)

class Solution(object):
    def baseUnitConversions(self, conversions):
        self.n = len(conversions) + 1
        self.res = [-1 for i in xrange(self.n)]
        self.g = defaultdict(list)
        for (a, b, c) in conversions:
            self.g[a].append((b, c))
            self.g[b].append((a, c))
        self.dfs(-1, 0, 1)
        return self.res

    def dfs(self, pre, cur, value):
        if self.res[cur] != -1:
            return
        self.res[cur] = value % MOD
        for (nxt, factor) in self.g[cur]:
            if nxt == pre:
                continue
            self.dfs(cur, nxt, value * factor % MOD)

            

        
