# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def canAttendMeetings(self, intervals):
        intervals.sort(key=lambda x: x.start)
        pre = -1
        for interval in intervals:
            (l, r) = interval.start, interval.end
            if l >= pre:
                pre = r
            else:
                return False
        return True
        
