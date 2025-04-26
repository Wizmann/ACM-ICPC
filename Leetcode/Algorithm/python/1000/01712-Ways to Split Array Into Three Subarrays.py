MOD = (10 ** 9) + 7

class Solution(object):
    def waysToSplit(self, nums):
        n = len(nums)
        presum = [0] + nums
        res = 0
        for i in xrange(1, n + 1):
            presum[i] += presum[i - 1]
        
        lb, ub = 1, 1
        for i in xrange(2, n):
            right = presum[n] - presum[i]
            while lb < i and presum[i] - presum[lb] > right:
                lb += 1
            mid_left = presum[i]
            while ub < i and presum[ub] <= mid_left - presum[ub]:
                ub += 1
            # print i, lb, ub
            if ub > lb:
                res += ub - lb
            res %= MOD
        return res % MOD
                
                
