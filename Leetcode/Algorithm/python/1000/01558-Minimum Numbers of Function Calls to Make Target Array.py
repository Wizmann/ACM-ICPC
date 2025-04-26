class Solution(object):
    def minOperations(self, nums):
        maxi = max(nums)
        res = 0
        for i in xrange(32):
            mask = (1 << i)
            if mask > maxi:
                break
            res += 1 if i > 0 else 0
            res += sum(map(lambda x: 1 if (x & mask) else 0, nums))
        return res
            
