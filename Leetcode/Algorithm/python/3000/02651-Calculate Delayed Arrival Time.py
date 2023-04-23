class Solution(object):
    def findDelayedArrivalTime(self, arrivalTime, delayedTime):
        return (arrivalTime + delayedTime) % 24
