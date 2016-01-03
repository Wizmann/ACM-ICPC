(n, m) = map(int, raw_input().split())
s = 0
for i in xrange(2, n + 1):
    s = (s + m) % i
print s + 1

