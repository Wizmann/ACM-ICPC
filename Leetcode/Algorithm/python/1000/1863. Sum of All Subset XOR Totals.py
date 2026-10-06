class Solution(object):
    def subsetXORSum(self, nums):
        n = len(nums)
        tot = 0
        for i in xrange(1 << n):
            cur = 0
            for j in xrange(n):
                if i & (1 << j):
                   cur ^= nums[j] 
            tot += cur
        return tot
                    
