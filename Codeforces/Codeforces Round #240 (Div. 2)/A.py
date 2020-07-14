(n, m) = map(int, raw_input().split())
bs = map(int, raw_input().split())

ts = [0 for i in xrange(n + 1)]

for b in bs:
    for i in xrange(b, n + 1):
        if not ts[i]:
            ts[i] = b

print ' '.join(map(str, ts[1:]))
