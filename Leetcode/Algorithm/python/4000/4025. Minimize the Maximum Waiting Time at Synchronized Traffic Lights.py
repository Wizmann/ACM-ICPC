class Solution(object):
    def minPenalty(self, period, lights, arrivalTime):
        lights.sort()
        n = len(lights)
        res = 0
        for t in arrivalTime:
            t %= period

            l, r = 0, len(lights) - 1
            while l <= r:
                m = (l + r) / 2
                if lights[m] <= t:
                    l = m + 1
                else:
                    r = m - 1
            # print t, l, r, lights
            if l == n:
                res = max(res, period - t)
        return res
