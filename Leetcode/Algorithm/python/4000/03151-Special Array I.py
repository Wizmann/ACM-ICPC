class Solution(object):
    def isArraySpecial(self, nums):
        n = len(nums)
        for i in xrange(0, n - 1):
            if (nums[i] % 2) ^ (nums[i + 1] % 2) == 0:
                return False
        return True
