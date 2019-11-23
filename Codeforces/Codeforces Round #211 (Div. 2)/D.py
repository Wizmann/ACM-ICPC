def do_solve(bs, ps, a, cur):
    n = len(bs)
    m = len(ps)

    tot = 0
    b = a
    for i in xrange(cur):
        if ps[i] > bs[n - cur + i]:
            delta = ps[i] - bs[n - cur + i]
            a -= delta
        tot += ps[i]

        if a < 0:
            return -1

    return max(0, tot - b)

def solve(n1, m1, a, bs, ps):
    l, r = 0, min(n1, m1)

    bs.sort()
    ps.sort()

    while l <= r:
        m = (l + r) >> 1

        if do_solve(bs, ps, a, m) != -1:
            l = m + 1
        else:
            r = m - 1
    #print r, do_solve(bs, ps, a, r)
    return r, do_solve(bs, ps, a, r)

assert solve(2, 2, 10, [5, 5], [7, 6]) == (2, 3)
assert solve(4, 5, 2, [8, 1, 1, 2], [6, 3, 7, 5, 2]) == (3, 8)

(n, m, a) = map(int, raw_input().split())
bs = map(int, raw_input().split())
ps = map(int, raw_input().split())

r, s = solve(n, m, a, bs, ps)
print r, s
