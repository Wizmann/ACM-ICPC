from collections import defaultdict

INF = 10 ** 10

class Solution(object):
    def minCost(self, houses, cost, m, n, target):
        dp = {}
        dp[(0, 0, 0)] = 0
        
        for i in xrange(len(houses)):
            cur = houses[i]
            for t in xrange(0, target + 1):
                for pre in xrange(0, n + 1):
                    for nxt in xrange(1, n + 1):
                        if cur != 0 and nxt != cur:
                            continue
                        c = 0
                        if cur == 0:
                            c = cost[i][nxt - 1]
                        k1 = (i, t, pre)
                        if k1 not in dp:
                            continue
                        if nxt == pre:
                            k2 = (i + 1, t, nxt)
                            if k2 not in dp:
                                dp[k2] = INF
                            dp[k2] = min(dp[k2], dp[k1] + c)
                        else:
                            k2 = (i + 1, t + 1, nxt)
                            if t + 1 > target:
                                continue
                            if k2 not in dp:
                                dp[k2] = INF
                            dp[k2] = min(dp[k2], dp[k1] + c)
        mini = INF
        for i in xrange(1, n + 1):
            mini = min(mini, dp.get((len(houses), target, i), INF))
        return -1 if mini >= INF else mini

                            

