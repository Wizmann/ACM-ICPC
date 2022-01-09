INF = 10 ** 10

class Solution(object):
    def minMoves(self, nums, limit):
        n = len(nums)
        point = [0 for i in xrange(limit * 2 + 1)]
        rng = [0 for i in xrange(limit * 2 + 1)]
        
        for i in xrange(n / 2):
            a = nums[i]
            b = nums[n - i - 1]
            point[a + b] -= 1
            rng[limit * 2] += 2
            rng[max(a, b) + limit] -= 2
            rng[max(a, b) + limit] += 1
            rng[min(a, b)] -= 1
            rng[min(a, b)] += 2
        res = INF
        pre = 0
        cur = 0
        for i in xrange(limit * 2, 1, -1):
            pre += rng[i]
            res = min(res, pre + point[i])
        return res
