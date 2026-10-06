INF = 10 ** 10

class Solution(object):
    def mincostTickets(self, days, costs):
        days = days
        n = max(days)
        
        dp = [INF for i in xrange(n + 1)]
        dp[0] = 0
        
        pre = 0
        for day in days:
            for i in xrange(pre, day):
                if dp[i] >= INF:
                    continue
                for t, j in enumerate([1, 7, 30]):
                    next = min(n, day + j - 1)
                    dp[next] = min(dp[next], dp[i] + costs[t])
            pre = day
        #print dp
        return dp[-1]
        
        
