class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        if not timeSeries:
            return 0
        res = 0
        st, end = -1, -1
        for t in timeSeries:
            if t > end:
                if st == -1:
                    pass
                else:
                    res += end - st + 1
                st = t
                end = t + duration - 1
            else:
                end = t + duration - 1
        return res + end - st + 1
