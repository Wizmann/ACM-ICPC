class Solution(object):
    def findMinDifference(self, timePoints):
        times = sorted(map(self.convertTime, timePoints))
        print times
        ans = self.timeDiff(times[0], times[-1])
        for i in xrange(1, len(times)):
            a, b = times[i - 1], times[i]
            ans = min(ans, self.timeDiff(a, b))
        return ans
        
    def convertTime(self, s):
        hh, mm = map(int, s.split(':'))
        return hh * 60 + mm
        
    def timeDiff(self, a, b):
        return min(b - a, a + 24 * 60 - b)
