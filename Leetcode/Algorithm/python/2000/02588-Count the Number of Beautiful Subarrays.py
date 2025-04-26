from collections import defaultdict

class Solution(object):
    def beautifulSubarrays(self, nums):
        d = defaultdict(int)
        d[0] = 1
        prefix = 0
        res = 0
        for num in nums:
            prefix ^= num
            res += d[prefix]
            d[prefix] += 1
        return res
