from collections import Counter

class Solution(object):
    def maxOperations(self, nums, k):
        c = Counter(nums)
        res = 0
        for v1 in sorted(c.keys()):
            v2 = k - v1
            if v1 < v2:
                res += min(c[v1], c[v2])
            elif v1 == v2:
                res += c[v1] / 2
        return res
