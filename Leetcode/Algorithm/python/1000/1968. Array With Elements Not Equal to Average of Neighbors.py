class Solution(object):
    def rearrangeArray(self, nums):
        nums.sort()
        n = len(nums)
        res = [-1 for i in xrange(n)]
        ptr = 0
        for i in xrange(0, (n + 1) / 2):
            res[ptr] = nums[i]
            ptr += 2
        ptr = 1
        for i in xrange((n + 1) / 2, n):
            res[ptr] = nums[i]
            ptr += 2
        return res
