INF = 10 ** 10

class Solution(object):
    def minPairSum(self, nums):
        nums.sort()
        n = len(nums)
        maxi = -INF
        for i in xrange(n / 2):
            l = i
            r = n - i - 1
            maxi = max(maxi, nums[l] + nums[r])
        return maxi
