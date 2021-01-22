from collections import defaultdict

INF = 10 ** 10

class Solution(object):
    def minSubarray(self, nums, p):
        d = defaultdict(list)
        n = len(nums)
        res = INF
        pre = 0
        for i in xrange(n):
            pre += nums[i]
            if pre % p == 0:
                res = min(res, n - i - 1)
            d[pre % p].append(i)
        if pre % p == 0:
            return 0
        cur = 0
        for i in xrange(n - 1, -1, -1):
            u = d[pre % p].pop()
            assert u == i
            pre -= nums[i]
            cur += nums[i]
            if cur % p == 0:
                res = min(res, i)
            if d[p - cur % p]:
                res = min(res, i - d[p - cur % p][-1] - 1)
        if res == INF:
            return -1
        return res
