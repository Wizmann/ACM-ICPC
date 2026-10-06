from collections import defaultdict

class Solution(object):
    def maximumUniqueSubarray(self, nums):
        d = defaultdict(int)
        l, r = 0, 0
        n = len(nums)
        res = 0
        tot = 0
        while l < n and r < n:
            r = max(l, r)
            cur = nums[r]
            if d[cur] == 0:
                d[cur] += 1
                tot += cur
                r += 1
            else:
                while l < n and d[cur] > 0:
                    d[nums[l]] -= 1
                    tot -= nums[l]
                    l += 1
            res = max(res, tot)
        return res
