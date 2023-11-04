class Solution(object):
    def minProcessingTime(self, processorTime, tasks):
        maxi = 0
        tasks.sort(reverse=True)
        processorTime.sort()
        for i, t in enumerate(processorTime):
            maxi = max(maxi, t + max(tasks[i * 4: (i + 1) * 4]))
        return maxi
