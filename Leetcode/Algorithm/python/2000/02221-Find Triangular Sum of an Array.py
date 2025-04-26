class Solution(object):
    def triangularSum(self, nums):
        while len(nums) > 1:
            nxt = []
            n = len(nums)
            for i in xrange(n - 1):
                nxt.append( (nums[i] + nums[i + 1]) % 10 )
            nums = nxt[:]
        return nums[0]
