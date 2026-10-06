class Solution(object):
    def minMoves(self, nums):
        m = min(nums)
        return sum(nums) - len(nums) * m
