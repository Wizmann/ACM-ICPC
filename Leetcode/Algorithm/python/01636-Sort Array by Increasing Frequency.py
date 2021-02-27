from collections import Counter

class Solution(object):
    def frequencySort(self, nums):
        c = Counter(nums)
        c = sorted(map(lambda (k, v): (v, -k), c.items()))
        res = []
        for (v, k) in c:
            res += [-k] * v
        return res
