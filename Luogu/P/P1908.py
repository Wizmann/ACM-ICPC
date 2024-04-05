INF = 10 ** 10

def solve(ns):
    n = len(ns)
    if n == 1:
        return 0
    a, b = ns[:n / 2], ns[n / 2:]
    tot = 0
    tot += solve(a)
    tot += solve(b)

    p, q = 0, 0
    ms = [-1 for i in xrange(n)]
    cur = 0
    # print a, b, tot
    while p < len(a) or q < len(b):
        pv = a[p] if p < len(a) else INF
        qv = b[q] if q < len(b) else INF

        if pv <= qv:
            ms[cur] = pv
            p += 1
        else:
            ms[cur] = qv
            q += 1
            tot += len(a) - p
        cur += 1
    for i in xrange(n):
        ns[i] = ms[i]
    # print a, b, tot
    return tot

n = int(raw_input())
ns = map(int, raw_input().split())

print solve(ns)
# print ns
