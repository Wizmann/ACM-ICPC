INF = 10 ** 10

class Solution(object):
    def maxSubArray(self, nums):
        ans = -INF
        cur = 0
        for num in nums:
            cur += num
            ans = max(ans, cur)
            if cur < 0:
                cur = 0
        return ans
