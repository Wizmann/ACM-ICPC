(n, m) = map(int, raw_input().split())

res = []

for i in xrange(n):
    if i % 2 == 0:
        res.append('#' * m)
    elif (i / 2) % 2 == 0:
        res.append('.' * (m - 1) + '#')
    else:
        res.append('#' + '.' * (m - 1))

for line in res:
    print line