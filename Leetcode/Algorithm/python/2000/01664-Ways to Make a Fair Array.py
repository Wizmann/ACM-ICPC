class Solution(object):
    def waysToMakeFair(self, nums):
        t1 = sum(nums[::2])
        t2 = sum(nums[1::2])
        
        n = len(nums)
        a, b = 0, 0
        cnt = 0
        for i in xrange(n):
            if i % 2 == 0:
                t1 -= nums[i]
            else:
                t2 -= nums[i]
            if a + t2 == b + t1:
                cnt += 1
            if i % 2 == 0:
                a += nums[i]
            else:
                b += nums[i]
        return cnt
