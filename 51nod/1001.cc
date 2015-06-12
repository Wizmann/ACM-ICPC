(k, n) = map(int, raw_input().split())
ns = sorted([int(raw_input()) for i in xrange(n)])
s = set(ns)

cnt = 0
for p in ns:
    q = k - p
    if q > p and q in s:
        print p, q
        cnt += 1

if not cnt:
    print 'No Solution'
