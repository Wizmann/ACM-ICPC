class Solution(object):
    def change(self, amount, coins):
        dp = [0 for i in xrange(amount + 1)]
        dp[0] = 1
        
        for coin in coins:
            for i in xrange(amount + 1):
                if not dp[i]:
                    continue
                next = i + coin
                if next > amount:
                    continue
                
                dp[next] += dp[i]
        return dp[amount]
