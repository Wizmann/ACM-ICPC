n = int(raw_input())
ns = sorted(map(int, [raw_input() for i in xrange(n)]))

res = 0
for i in xrange(n):
    res += (n - i) * ns[i]
print res
