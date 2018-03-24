# -*- coding:utf-8 -*-

MOD = 1000000007

class Coins:
    def countWays(self, n):
        dp = [0 for i in xrange(n + 1)]
        dp[0] = 1
        
        for coin in [1, 5, 10, 25]:
            for i in xrange(n + 1):
                if i + coin <= n:
                    dp[i + coin] = (dp[i + coin] + dp[i]) % MOD
        return dp[n]
