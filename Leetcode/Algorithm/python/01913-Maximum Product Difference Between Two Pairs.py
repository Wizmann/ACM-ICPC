class Solution(object):
    def maxProductDifference(self, nums):
        nums.sort(reverse=True)
        return nums[0] * nums[1] - nums[-1] * nums[-2]
