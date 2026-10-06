INF = 10 ** 10

class Solution(object):
    def minimumCoins(self, prices):
        n = len(prices)
        dp = [INF for i in xrange(n + 1)]
        dp[0] = 0
        for i in xrange(1, n + 1):
            for j in xrange(i - 1, -1, -1):
                r = 2 * j
                if i == n and r >= i:
                    dp[i] = min(dp[i], dp[j])
                if r + 1 >= i:
                    dp[i] = min(dp[i], dp[j] + prices[i - 1])
                else:
                    break
        return dp[-1]
