INF = 0xdeadbeef

class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        n = len(prices)
        if n < 2:
            return 0
        ans = 0
        maxi, mini = -INF, INF
        maxis, minis = [], []
        for i in xrange(n):
            mini = min(mini, prices[i])
            minis.append(mini)
        for i in xrange(n - 1, -1, -1):
            maxi = max(maxi, prices[i])
            maxis.append(maxi)
        maxis = maxis[::-1]
        for (a, b) in zip(minis, maxis):
            ans = max(ans, b - a)
        return ans
