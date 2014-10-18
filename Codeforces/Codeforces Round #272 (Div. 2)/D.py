(n, k) = map(int, raw_input().split())

print (6 * (n - 1) + 5) * k

for i in xrange(n):
    ns = map(lambda x: k * (6 * i + x), [1, 2, 3, 5])
    print ' '.join(map(str, ns))
