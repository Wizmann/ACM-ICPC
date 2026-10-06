class Solution(object):
    def maxIceCream(self, costs, coins):
        res = 0
        for cost in sorted(costs):
            if cost <= coins:
                coins -= cost
                res += 1
            else:
                break
        return res
