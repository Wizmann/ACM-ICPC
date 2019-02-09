# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def intervalIntersection(self, A, B):
        res = []
        while A and B:
            a = A[0]
            b = B[0]
            
            l = max(a.start, b.start)
            r = min(a.end, b.end)

            if l <= r:
                res.append(Interval(l, r))
                
            if a.end > b.end:
                B.pop(0)
            else:
                A.pop(0)
        return res
