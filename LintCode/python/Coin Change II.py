class Solution:
    """
    @param amount: a total amount of money amount
    @param coins: the denomination of each coin
    @return: the number of combinations that make up the amount
    """
    def change(self, amount, coins):
        dp = [0 for i in xrange(amount + 1)]
        dp[0] = 1
        
        for coin in coins:
            u = 1
            while u * coin <= amount:
                for i in xrange(amount - 1, -1, -1):
                    if not dp[i]:
                        continue
                    if i + u * coin > amount:
                        continue
                    dp[i + u * coin] += dp[i]
                u = u << 1
        return dp[amount]
