class Solution(object):
    def longestAlternatingSubarray(self, nums, threshold):
        res = 0
        n = len(nums)
        for i in xrange(n):
            for j in xrange(i, n):
                if nums[i] % 2 != 0:
                    continue
                if max(nums[i: j + 1]) > threshold:
                    continue
                for k in xrange(i, j):
                    if nums[k] % 2 == nums[k + 1] % 2:
                        break
                else:
                    res = max(res, j + 1 - i)
        return res
                
