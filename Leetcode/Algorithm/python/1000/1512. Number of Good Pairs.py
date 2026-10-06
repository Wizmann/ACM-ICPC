from collections import Counter

class Solution(object):
    def numIdenticalPairs(self, nums):
        c = Counter(nums)
        res = 0
        for k, v in c.items():
            res += v * (v - 1) / 2
        return res
