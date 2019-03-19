INF = 10 ** 10
class Solution(object):
    def shipWithinDays(self, weights, D):
        l, r = 0, INF
        while l <= r:
            m = (l + r) / 2
            cnt = 0
            tot = 0
            for w in weights:
                if w > m:
                    cnt = INF
                    break
                tot += w
                if tot > m:
                    cnt += 1
                    tot = w
            if tot:
                cnt += 1
            if cnt <= D:
                r = m - 1
            else:
                l = m + 1
        return l
