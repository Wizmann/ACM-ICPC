class Solution(object):
    def busyStudent(self, startTime, endTime, queryTime):
        n = len(startTime)
        cnt = 0
        for i in xrange(n):
            if startTime[i] <= queryTime <= endTime[i]:
                cnt += 1
        return cnt
