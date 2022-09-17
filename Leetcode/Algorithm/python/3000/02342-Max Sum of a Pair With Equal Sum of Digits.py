from collections import defaultdict

class Solution(object):
    def maximumSum(self, nums):
        d = defaultdict(int)
        res = -1
        for num in nums:
            tot = sum(map(int, str(num)))
            if tot in d:
                res = max(res, d[tot] + num)
            d[tot] = max(d[tot], num)
        return res
