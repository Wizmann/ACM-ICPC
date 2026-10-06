class Solution(object):
    def getSumAbsoluteDifferences(self, nums):
        n = len(nums)
        tot = sum(nums)
        pre = 0
        res = [0 for i in xrange(n)]
        for i in xrange(n):
            lcnt = i
            rcnt = n - i - 1
            lsum = pre
            rsum = tot - nums[i] - lsum
            
            res[i] = (nums[i] * lcnt - lsum) + (rsum - nums[i] * rcnt)
            
            pre += nums[i]
        return res
            
