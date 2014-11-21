# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

INF = 0xdeadbeef

class Solution:
    # @param intervals, a list of Interval
    # @return a list of Interval
    def merge(self, intervals):
        if not intervals:
            return []
        intervals.append(Interval(INF, INF))
        intervals.sort(key=lambda x: x.start)
        res = []
        now = intervals[0]
        for interval in intervals:
            if interval.start <= now.end:
                now.end = max(interval.end, now.end)
            else:
                res.append(now)
                now = interval
        return res
