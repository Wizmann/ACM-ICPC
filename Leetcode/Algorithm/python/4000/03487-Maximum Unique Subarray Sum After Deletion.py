class Solution(object):
    def maxSum(self, nums):
        return max(nums) if max(nums) <= 0 else sum(set(filter(lambda x : x >= 0, nums)))
