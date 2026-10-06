INF = 10 ** 10

class Solution(object):
    def maximumProduct(self, nums):
        nums = sorted(filter(lambda x: x != 0, nums))
        if len(nums) < 3:
            return 0
        n = len(nums)
        maxi = -INF
        for i in xrange(len(nums)):
            maxi = max(maxi, nums[i] * nums[(i + 1) % n] * nums[(i + 2) % n])
        return maxi
