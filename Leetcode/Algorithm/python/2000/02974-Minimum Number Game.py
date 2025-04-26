class Solution(object):
    def numberGame(self, nums):
        n = len(nums)
        nums.sort()
        for i in xrange(0, n, 2):
            nums[i], nums[i + 1] = nums[i + 1], nums[i]
        return nums
