class Solution(object):
    def missingNumber(self, nums):
        n = len(nums)
        return sum(range(0, n + 1)) - sum(nums)
        
