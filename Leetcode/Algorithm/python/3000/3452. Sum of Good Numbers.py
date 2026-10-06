class Solution(object):
    def sumOfGoodNumbers(self, nums, k):
        n = len(nums)
        res = 0
        for i in xrange(n):
            if (i - k < 0 or nums[i] > nums[i - k]) and \
               (i + k >= n or nums[i] > nums[i + k]):
                res += nums[i]
        return res
