class Solution(object):
    def findPrefixScore(self, nums):
        n = len(nums)
        maxi = 0
        res = []
        for num in nums:
            maxi = max(maxi, num)
            res.append(num + maxi)
        for i in xrange(1, n):
            res[i] += res[i - 1]
        return res
