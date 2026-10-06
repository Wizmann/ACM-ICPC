INF = 10 ** 10

class Solution(object):
    def minimumDifference(self, nums, k):
        nums.sort()
        n = len(nums)
        ans = INF
        for i in xrange(n - k + 1):
            ans = min(ans, nums[i + k - 1] - nums[i])
        return ans
