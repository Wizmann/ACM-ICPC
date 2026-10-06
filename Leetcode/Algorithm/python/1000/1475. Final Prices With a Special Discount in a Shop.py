class Solution(object):
    def finalPrices(self, prices):
        n = len(prices)
        res = []
        for i in xrange(n):
            mini = prices[i]
            for j in xrange(i + 1, n):
                if prices[j] <= prices[i]:
                    mini = min(mini, prices[i] - prices[j])
                    break
            res.append(mini)
        return res
