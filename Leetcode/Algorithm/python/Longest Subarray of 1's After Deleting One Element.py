class Solution(object):
    def longestSubarray(self, nums):
        n = len(nums)
        dp1 = [-1 for i in xrange(n)]
        dp2 = [-1 for i in xrange(n)]
        
        pre = 0
        for i in xrange(n):
            if nums[i] == 1:
                pre += 1
                dp1[i] = pre
            else:
                pre = 0
                dp1[i] = pre
        pre = 0
        for i in xrange(n - 1, -1, -1):
            if nums[i] == 1:
                pre += 1
                dp2[i] = pre
            else:
                pre = 0
                dp2[i] = pre
        # print dp1
        # print dp2
        res = 0
        for i in xrange(n):
            tot = 0
            if i - 1 >= 0:
                tot += dp1[i - 1]
            if i + 1 < n:
                tot += dp2[i + 1]
            res = max(res, tot)
        return res
