INF = 10 ** 10

class Solution(object):
    def removeCoveredIntervals(self, intervals):
        intervals.sort(key=lambda (a, b): (a, -b))
        pre = -INF
        ans = 0
        for (a, b) in intervals:
            if b - 1 >= pre:
                ans += 1
                pre = b
        return ans
