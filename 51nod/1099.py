n = int(raw_input())
ns = [tuple(map(int, raw_input().split())) for i in xrange(n)]

ns.sort(cmp=lambda x, y: cmp(x[1] + y[0], y[1] + x[0]))

a, b = 0, 0

for item in ns:
    if a - b < item[0]:
        a = b + item[0]
    b += item[1]

print a
