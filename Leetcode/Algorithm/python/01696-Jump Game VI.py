INF = 10 ** 10

class Solution(object):
    def maxResult(self, nums, k):
        n = len(nums)
        q = [0]
        dp = [-INF for i in xrange(n)]
        dp[0] = nums[0]
        for i in xrange(1, n):
            while q and i - q[0] > k:
                q.pop(0)
            assert q
            dp[i] = dp[q[0]] + nums[i]
            
            while q and dp[i] > dp[q[-1]]:
                q.pop()
            q.append(i)
        return dp[-1]
