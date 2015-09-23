(n, p) = map(int, raw_input().split())

res = 1
for i in xrange(1, n + 1):
    res = (res * i) % p
print res
