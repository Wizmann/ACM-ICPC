# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    # @param intervals, a list of Interval
    # @return a list of Interval
    def merge(self, intervals):
        INF = 0xdeadbeef
        intervals.append(Interval(INF, INF))
        intervals.sort(key=lambda x: x.start)
        res = []
        cur = intervals[0]
        
        for interval in intervals:
            if interval.start > cur.end:
                res.append(cur)
                cur = interval
            else:
                cur.end = max(interval.end, cur.end)
        
        return res
            
