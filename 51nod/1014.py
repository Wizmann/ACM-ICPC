(p, a) = map(int, raw_input().split())
ns = []

for i in xrange(0, p + 1):
    if (i * i) % p == a:
        ns.append(i)

if ns:
    print ' '.join(map(str, ns))
else:
    print 'No Solution'
