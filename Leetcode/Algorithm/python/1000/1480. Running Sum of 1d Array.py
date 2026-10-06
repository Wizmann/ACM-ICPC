class Solution(object):
    def runningSum(self, nums):
        n = len(nums)
        for i in xrange(1, n):
            nums[i] += nums[i - 1]
        return nums
