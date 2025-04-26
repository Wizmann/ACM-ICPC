INF = 10 ** 10

class Solution(object):
    def maxAlternatingSum(self, nums):
        a, b = 0, 0
        res = -INF
        for num in nums:
            a, b = max(a, b - num), max(b, a + num)
            res = max(res, a, b)
        return res
