class Solution(object):
    def minMoves(self, nums):
        n = len(nums)
        return n * max(nums) - sum(nums)
