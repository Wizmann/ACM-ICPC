class Solution(object):
    def maxScore(self, nums):
        n = len(nums)
        nums.sort(reverse=True)
        prefix = 0
        cnt = 0
        for i in xrange(n):
            prefix += nums[i]
            if prefix <= 0:
                break
            cnt += 1
        return cnt
