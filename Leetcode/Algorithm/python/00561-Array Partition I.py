class Solution(object):
    def arrayPairSum(self, nums):
        return sum(sorted(nums)[::2])
