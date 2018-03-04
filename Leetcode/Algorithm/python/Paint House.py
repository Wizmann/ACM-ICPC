INF = 10 ** 10

class Solution(object):
    def minCost(self, costs):
        dp = [0, 0, 0]
        for cost in costs:
            next = [INF, INF, INF]
            for i in xrange(3):
                for j in xrange(3):
                    if i == j:
                        continue
                    next[i] = min(next[i], dp[j] + cost[i])
            dp = next
            print dp
        return min(dp)
