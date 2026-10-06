from collections import defaultdict

INF = 10 ** 10

def lower_bound(items, target):
    l, r = 0, len(items) - 1
    while l <= r:
        m = (l + r) / 2
        if items[m] < target:
            l = m + 1
        else:
            r = m - 1
    return l

assert lower_bound([1, 2, 2, 3], 2) == 1

class Solution(object):
    def solveQueries(self, nums, queries):
        res = []
        n = len(nums)
        d = defaultdict(list)
        for i, num in enumerate(nums):
            d[num].append(i)
        for q in queries:
            a = nums[q]
            p = lower_bound(d[a], q)
            l = len(d[a])
            p1, p2 = d[a][p - 1], d[a][(p + 1) % l]
            # print a, d[a], p, p1, p2
            mini = INF
            if p1 != q:
                mini = min(mini, abs(q - p1), abs(p1 + n - q), abs(n + q - p1))
            if p2 != q:
                mini = min(mini, abs(q - p2), abs(p2 + n - q), abs(n + q - p2))
            res.append(-1 if mini >= INF else mini)
        return res
