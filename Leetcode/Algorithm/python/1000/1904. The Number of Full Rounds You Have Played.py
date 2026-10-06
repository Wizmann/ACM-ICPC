class Solution(object):
    def numberOfRounds(self, startTime, finishTime):
        startTime = map(int, startTime.split(':'))
        finishTime = map(int, finishTime.split(':'))
        if finishTime < startTime:
            finishTime[0] += 24
        if startTime[1] % 15 != 0:
            startTime[1] = (startTime[1] / 15 + 1) * 15
        if startTime[1] == 60:
            startTime[0] += 1
            startTime[1] = 0
        if finishTime[1] % 15 != 0:
            finishTime[1] = (finishTime[1] / 15) * 15
        delta = (finishTime[0] - startTime[0]) * 60 + (finishTime[1] - startTime[1])
        return max(0, delta / 15)
