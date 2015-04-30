(n, m) = map(int, raw_input().split())

s = 0
for i in xrange(m):
    (a, b, c) = map(int, raw_input().split())
    s += (b - a + 1) * c
print s / n
