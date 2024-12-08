class Enemy(object):
    def __init__(self, d, t):
        self.d = d
        self.t = t

class Solution(object):
    def minDamage(self, power, damage, health):
        n = len(damage)
        es = []
        m = 0
        d = 0
        for i in xrange(n):
            t = (health[i] + power - 1) / power
            e = Enemy(damage[i], t)
            m += t
            d += damage[i]
            es.append(e)
        es.sort(key=lambda e: 1.0 * e.d / e.t, reverse=True)

        tot = 0
        for e in es:
            d -= e.d
            tot += d * e.t + e.d * e.t
            m -= e.t
        return tot

