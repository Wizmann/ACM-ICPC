from math import sqrt

INF = 10 ** 18

class Solution(object):
    def repairCars(self, ranks, cars):
        l, r = 0, INF
        while l <= r:
            m = (l + r) / 2
            tot = self.check(ranks, m, cars)
            if tot >= cars:
                r = m - 1
            else:
                l = m + 1
        return l

    def check(self, ranks, m, n):
        tot = 0
        for r in ranks:
            t = int(sqrt(m / r))
            tot += t
            if tot > n:
                break
        return tot
