class Solution(object):
    def addRungs(self, rungs, dist):
        cur = 0
        cnt = 0
        for r in rungs:
            diff = r - cur
            if diff > dist:
                u = (diff + dist - 1) / dist - 1
                cnt += u
                cur += dist * u
            cur = r
        return cnt
