INF = 10 ** 7

class Solution(object):
    def minSpeedOnTime(self, dist, hour):
        l, r = 1, INF
        
        def check(m):
            res = 0
            for d in dist[:-1]:
                t = (d + m - 1) / m
                res += t
            res += 1.0 * dist[-1] / m
            return res
        
        while l <= r:
            m = (l + r) / 2
            t = check(m)
            if t <= hour:
                r = m - 1
            else:
                l = m + 1
        return l if l <= INF else -1
