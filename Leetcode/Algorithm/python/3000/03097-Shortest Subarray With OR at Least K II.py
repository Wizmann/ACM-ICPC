from collections import defaultdict
INF = 10 ** 10

def makeint(d):
    res = 0
    for i in xrange(32):
        if d.get(i, 0):
            res += 1 << i
    return res

class Solution(object):
    def minimumSubarrayLength(self, nums, k):
        n = len(nums)
        l, r = 0, 0
        mini = INF
        d = defaultdict(int)
        while l < n and r < n:
            for i in xrange(32):
                if nums[r] & (1 << i):
                    d[i] += 1
            r += 1

            while l < r and makeint(d) >= k:
                mini = min(mini, r - l)
                for i in xrange(32):
                    if nums[l] & (1 << i):
                        d[i] -= 1
                l += 1
        if mini >= INF:
            return -1
        return mini
