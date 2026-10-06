class Solution(object):
    def applyOperations(self, nums):
        n = len(nums)
        for i in xrange(n - 1):
            if nums[i] == nums[i + 1]:
                nums[i] *= 2
                nums[i + 1] = 0
        return (filter(lambda x: x, nums) + [0] * n)[:n]
