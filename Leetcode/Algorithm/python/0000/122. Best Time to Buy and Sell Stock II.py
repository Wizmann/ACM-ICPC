class Solution:
    def maxProfit(self, prices):
        if not prices:
            return 0
        ans, now = 0, -prices[0]
        for price in prices:
            if price + now >= 0:
                ans += price + now
            now = -price
        return ans
