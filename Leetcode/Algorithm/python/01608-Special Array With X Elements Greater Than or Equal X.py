class Solution(object):
    def specialArray(self, nums):
        l, r = 0, 0
        nums.sort()
        n = len(nums)
        for i in xrange(n):
            cnt = n - i
            r = nums[i]
            if l <= cnt <= r:
                return cnt
            l = r + 1
        return -1
        
