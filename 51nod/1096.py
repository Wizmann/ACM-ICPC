n = int(raw_input())
ns = sorted([int(raw_input()) for i in xrange(n)])

pivot = ns[n / 2]
print sum(map(lambda x: abs(pivot - x), ns))
