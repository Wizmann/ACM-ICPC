n = int(raw_input())

res = [ [] for i in xrange(n) ]
cur = n * n

while cur:
    for i in xrange(n):
        res[i].append(cur)
        cur -= 1
    for i in xrange(n - 1, -1, -1):
        res[i].append(cur)
        cur -= 1

tot = (1 + n * n) * n * n / 2 / n
for line in res:
    assert sum(line) == tot
    print ' '.join(map(str, line))