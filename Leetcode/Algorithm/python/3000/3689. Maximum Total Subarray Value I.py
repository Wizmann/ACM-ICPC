class Solution(object):
    def maxTotalValue(self, nums, k):
        u = max(nums) - min(nums)
        return u * k
