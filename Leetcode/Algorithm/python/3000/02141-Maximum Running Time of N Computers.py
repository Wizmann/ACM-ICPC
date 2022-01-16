INF = 10 ** 14
class Solution(object):
    def maxRunTime(self, n, batteries):
        tot = sum(batteries)
        l, r = min(batteries), tot / n
        while l <= r:
            m = (l + r) / 2

            if self.check(n, batteries, m):
                l = m + 1
            else:
                r = m - 1
        return r

    def check(self, n, batteries, m):
        tot = 0
        for b in batteries:
            b = min(b, m)
            tot += b
        # print computers
        return tot >= n * m
'''
^^^^TEST^^^^
2
[3, 3, 3]
-------
4
$$$TEST$$$

^^^^TEST^^^^
2
[1, 1, 1, 1]
-------
2
$$$TEST$$$

^^^^TEST^^^^
3
[10, 10, 3, 5]
-------
8
$$$TEST$$$
'''

