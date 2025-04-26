from collections import defaultdict

INF = 10 ** 30

class Solution(object):
    def minCost(self, nums, k):
        dp = defaultdict(lambda: INF)
        dp[0] = 0
        n = len(nums)

        for i in xrange(1, n + 1):
            d = defaultdict(int)
            cost = k
            for j in xrange(i, n + 1):
                cur = nums[j - 1]
                d[cur] += 1
                if d[cur] == 2:
                    cost += 2
                elif d[cur] > 2:
                    cost += 1
                dp[j] = min(dp[j], dp[i - 1] + cost)
                if dp[j] >= dp[n]:
                    break
        return dp[n]
