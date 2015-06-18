(n, l) = map(int, raw_input().split())
ns = [int(raw_input()) for i in xrange(n)]

a = max(map(lambda x: min(x, l - x), ns))
b = max(map(lambda x: max(x, l - x), ns))

print a, b
