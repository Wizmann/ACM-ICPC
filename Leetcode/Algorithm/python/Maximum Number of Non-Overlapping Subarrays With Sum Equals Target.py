class Solution(object):
    def maxNonOverlapping(self, nums, target):
        nums = [0] + nums
        n = len(nums)
        d = {0: 0}
        pre = 0
        dp = [0 for i in xrange(n)]
        for i in xrange(1, n):
            pre += nums[i]
            dp[i] = dp[i - 1]

            l = d.get(pre - target, -1)
            if l >= 0:
                dp[i] = max(dp[i], dp[l] + 1)
            d[pre] = i
        return dp[n - 1]

S = Solution()
assert S.maxNonOverlapping([1,1,1,1,1], 2) == 2
assert S.maxNonOverlapping([-1,3,5,1,4,2,-9], 6) == 2
assert S.maxNonOverlapping([-2,6,6,3,5,4,1,2,8], 10) == 3
assert S.maxNonOverlapping([0,0,0], 0) == 3
