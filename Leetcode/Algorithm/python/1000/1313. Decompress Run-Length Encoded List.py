class Solution(object):
    def decompressRLElist(self, nums):
        res = []
        n = len(nums)
        for i in xrange(0, n, 2):
            a, b = nums[i], nums[i + 1]
            res += [b] * a
        return res
