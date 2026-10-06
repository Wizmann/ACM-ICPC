class Solution(object):
    def waysToSplitArray(self, nums):
        tot = sum(nums)
        pre = 0
        n = len(nums)
        res = 0
        for i in xrange(n - 1):
            pre += nums[i]
            tot -= nums[i]
            
            if pre >= tot:
                res += 1
        return res
