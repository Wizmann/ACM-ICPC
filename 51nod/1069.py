n = int(raw_input())
ns = map(int, [raw_input() for i in xrange(n)])
print 'B' if reduce(lambda x, y: x ^ y, ns) == 0 else 'A'
