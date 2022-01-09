INF = 10 ** 10

class Solution(object):
    def minOperations(self, nums, x):
        n = len(nums)
        d = {}
        pre = 0
        d[0] = n
        for i in xrange(n - 1, -1, -1):
            pre += nums[i]
            d[pre] = i
        pre = 0
        res = INF
        for i in xrange(n):
            u = x - pre
            if u in d and d[u] >= i:
                res = min(res, i + n - d[u])
            pre += nums[i]
        if res == INF:
            return -1
        return res
