n = int(raw_input())
ns = []
for i in xrange(n):
    (a, b) = map(int, raw_input().split())
    ns.append((a, b))
ns.sort()

day = 0
for (a, b) in ns:
    if day <= b:
        day = b
    else:
        day = a

print day
