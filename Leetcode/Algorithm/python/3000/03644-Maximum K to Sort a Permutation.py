INF = 0xFFFFFFFF

class Solution(object):
    def sortPermutation(self, nums):
        n = len(nums)
        res = INF
        for i in xrange(n):
            if nums[i] != i:
                res &= nums[i]
        if res == INF:
            return 0
        return res
