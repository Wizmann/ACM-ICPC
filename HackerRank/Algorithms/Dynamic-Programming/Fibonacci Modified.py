a, b, n = map(int, raw_input().split())

for i in xrange(n - 1):
    a, b = b, a + b * b

print a
