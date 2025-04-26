from collections import defaultdict

def maxProd(items):
    assert len(items) >= 3
    maxi = 0
    maxi = max(maxi, items[0] * items[1] * items[2])
    maxi = max(maxi, items[-1] * items[-2] * items[-3])
    maxi = max(maxi, items[-1] * items[-2] * items[0])
    maxi = max(maxi, items[0] * items[1] * items[-1])
    return maxi

class Solution(object):
    def placedCoins(self, edges, cost):
        self.n = len(cost)
        self.g = defaultdict(list)
        self.cost = cost
        for (a, b) in edges:
            self.g[a].append(b)
            self.g[b].append(a)
        self.res = [-1 for i in xrange(self.n)]
        self.dfs(-1, 0)
        return self.res

    def dfs(self, pre, cur):
        subsize = 1
        maxi = [self.cost[cur]]
        for nxt in self.g[cur]:
            if nxt == pre:
                continue
            subsize_, maxi_ = self.dfs(cur, nxt)
            subsize += subsize_
            maxi += maxi_
        maxi.sort()
        if len(maxi) >= 3:
            maxi = maxi[0:3] + maxi[3:][-3:]
            self.res[cur] = maxProd(maxi)
        else:
            self.res[cur] = 1
        return subsize, maxi
