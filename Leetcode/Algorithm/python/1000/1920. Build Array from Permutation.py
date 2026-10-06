class Solution(object):
    def buildArray(self, nums):
        n = len(nums)
        res = [-1 for i in xrange(n)]
        
        for i, num in enumerate(nums):
            res[i] = nums[nums[i]]
        return res
        
