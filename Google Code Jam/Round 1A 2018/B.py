import sys

class Casher(object):
    def __init__(self, m, s, p):
        self.m = m
        self.s = s
        self.p = p

def check(cashers, t, r, b):
    cashers.sort(key=lambda c: min(c.m, (t - c.p) / c.s), reverse=True)

    assert r <= len(cashers)

    for i in xrange(r):
        c = cashers[i]
        u = (t - c.p) / c.s
        u = max(0, u)
        u = min(u, c.m)

        b -= u
    return b <= 0


if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(1, T + 1):
        print 'Case #%d:' % case_,

        r, b, c = map(int, raw_input().split())

        cashers = []
        for i in xrange(c):
            (m, s, p) = map(int, raw_input().split())
            cashers.append(Casher(m, s, p))

        ll, rr = 0, 10 ** 30

        while ll <= rr:
            m = (ll + rr) / 2

            if check(cashers, m, r, b):
                rr = m - 1
            else:
                ll = m + 1
        print ll




        

