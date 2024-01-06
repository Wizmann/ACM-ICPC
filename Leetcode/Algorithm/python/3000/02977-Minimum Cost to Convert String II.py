from collections import defaultdict

MOD = (1 << 61) - 1
INF = 2 ** 63

class Solution(object):
    def minimumCost(self, source, target, original, changed, cost):
        n = len(source)
        m = len(cost)

        g = defaultdict(list)
        for i in xrange(m):
            a = original[i]
            b = changed[i]
            c = cost[i]
            g[a].append((c, b))

        cc = {}
        for i in xrange(m):
            q = [original[i]]
            dis = defaultdict(lambda: INF)
            dis[original[i]] = 0
            while q:
                cur = q.pop(0)
                d = dis[cur]
                for cost, nxt in g[cur]:
                    if d + cost < dis[nxt]:
                        dis[nxt] = d + cost
                        q.append(nxt)
            cc[original[i]] = dis


        dp = [INF for i in xrange(n + 1)]
        dp[0] = 0
        for i in xrange(1, n + 1):
            if target[i - 1] == source[i - 1]:
                dp[i] = dp[i - 1]
            for key, nxts in cc.items():
                u = len(key)
                # print i, source[i - u: i], key
                if u <= i and source[i - u: i] == key:
                    for nxt, cost in nxts.items():
                        # print '\t', target[i - u: i], nxt
                        if target[i - u: i] == nxt:
                            dp[i] = min(dp[i], dp[i - u] + cost)
        # print dp
        if dp[n] == INF:
            return -1
        return dp[n]

