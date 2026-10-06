class Solution(object):
    def checkArithmeticSubarrays(self, nums, l, r):
        res = []
        for (ll, rr) in zip(l, r):
            res.append(self.check(nums[ll: rr + 1]))
        return res
    
    def check(self, nums):
        n = len(nums)
        if n <= 1:
            return True
        nums.sort()
        k = (nums[-1] - nums[0]) / (n - 1)
        cur = nums[0]
        for i in xrange(1, n):
            if nums[i] != cur + k:
                return False
            cur += k
        return True
