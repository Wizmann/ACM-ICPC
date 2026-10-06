from collections import defaultdict

class Solution(object):
    def resultsArray(self, nums, k):
        for i, num in enumerate(nums):
            nums[i] = num - i
        n = len(nums)
        p, q = 0, 0
        d = defaultdict(int)
        res = []
        while p < n and q < n:
            d[nums[q]] += 1
            q += 1
            while q - p > k:
                d[nums[p]] -= 1
                if not d[nums[p]]:
                    del d[nums[p]]
                p += 1
            if q - p == k:
                if len(d) == 1:
                    res.append(d.keys()[0] + q - 1)
                else:
                    res.append(-1)
        return res
