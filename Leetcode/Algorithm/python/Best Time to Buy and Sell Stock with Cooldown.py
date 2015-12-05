INF = 0x3f3f3f3f

class Solution(object):
    def maxProfit(self, prices):
        sold, cooldown, hold = 0, -INF, -INF
        for price in prices:
            hold_ = max(hold, sold - price)
            cooldown_ = hold + price
            sold_ = max(sold, cooldown)
            sold, cooldown, hold = sold_, cooldown_, hold_
            print sold, cooldown, hold
        return max(sold, cooldown)
        
