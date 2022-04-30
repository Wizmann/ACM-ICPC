INF = 10 ** 10

class Solution(object):
    def findClosestNumber(self, nums):
        res = INF
        for num in nums:
            if abs(num) < abs(res):
                res = num
            elif abs(num) == abs(res):
                res = max(res, num)
        return res
