class Solution(object):
    def alternatingSubarray(self, nums):
        res = -1
        n = len(nums)
        for i in xrange(n):
            flag = 0
            for j in xrange(i + 1, n):
                delta = nums[j] - nums[j - 1]
                if delta == (-1) ** flag:
                    res = max(res, j - i + 1)
                else:
                    break
                flag ^= 1
        return res
