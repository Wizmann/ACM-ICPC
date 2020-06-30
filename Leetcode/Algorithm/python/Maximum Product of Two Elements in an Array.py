class Solution(object):
    def maxProduct(self, nums):
        nums.sort()
        a, b = nums[-1], nums[-2]
        return (a - 1) * (b - 1)
