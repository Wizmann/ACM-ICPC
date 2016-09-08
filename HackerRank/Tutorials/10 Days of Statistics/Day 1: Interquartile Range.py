def median(ns):
    n = len(ns)
    if n % 2 == 0:
        return 1.0 * (ns[n / 2 - 1] + ns[n / 2]) / 2
    else:
        return ns[n / 2]

n = int(raw_input())
ns = map(int, raw_input().split())
cs = map(int, raw_input().split())

ns = sorted(reduce(lambda x, y: x + y, map(lambda (x, y): [x] * y, zip(ns, cs)), []))
n = len(ns)


l, r = ns[:n / 2], ns[(n + 1) / 2:]


print '%.1f' % (median(r) - median(l))
