from collections import defaultdict

class Solution(object):
    def maximizeSumOfWeights(self, edges, k):
        self.g = defaultdict(list)
        for (a, b, c) in edges:
            self.g[a].append((b, c))
            self.g[b].append((a, c))

        self.k = k
        self.dp = {}
        return self.dfs(-1, 0, True)

    def dfs(self, pre, cur, flag):
        key = (cur, flag)
        if key in self.dp:
            return self.dp[key]

        sub = []
        tot = 0
        for (nxt, cost) in self.g[cur]:
            if pre == nxt:
                continue
            a = self.dfs(cur, nxt, True)
            b = self.dfs(cur, nxt, False) + cost
            sub.append(b - a)
            tot += a
        conn = min(len(sub), self.k - (0 if flag else 1))
        sub.sort(reverse=True)
        for i in xrange(conn):
            tot += max(0, sub[i])
        self.dp[key] = tot
        return tot
