INF = 10 ** 10

class Solution(object):
    def maxSumDivThree(self, nums):
        dp = [0, -INF, -INF]
        for num in nums:
            nxt = dp[:]
            for i in xrange(3):
                j = (num + i) % 3
                nxt[j] = max(nxt[j], dp[i] + num)
            dp = nxt[:]
            #print dp
        return dp[0]
