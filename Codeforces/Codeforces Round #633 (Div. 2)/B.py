def solve(ns):
    ns.sort()
    n = len(ns)
    res = []
    p, q = 0, n - 1
    while p <= q:
        if p <= q:
            res.append(ns[q])
            q -= 1
        if p <= q:
            res.append(ns[p])
            p += 1
    return res[::-1]

def verify(ns):
    INF = 10 ** 10
    pre = -INF
    n = len(ns)
    for i in xrange(1, n):
        assert abs(ns[i] - ns[i - 1]) >= pre
        pre = abs(ns[i] - ns[i - 1])
    return True

def test():
    from random import randint
    for i in xrange(100):
        n = randint(1, 200)
        ns = [randint(-100, 100) for i in xrange(n)]
        res = solve(ns)
        assert verify(res)


T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())
    res = solve(ns)
    for item in res:
        print item,
    print ''
