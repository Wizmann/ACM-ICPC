from collections import Counter

class Solution(object):
    def sumDivisibleByK(self, nums, k):
        c = Counter(nums)
        res = 0
        for key, value in c.items():
            if value % k == 0:
                res += key * value
        return res
