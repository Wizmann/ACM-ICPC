# Result: Nov 25, 2013 8:43:08 AM   Wizmann  A - Dima and Guards     Python 2   Accepted    46 ms   0 KB
k = int(raw_input())

guards = []
for i in xrange(4):
    (a, b, c, d) = map(int, raw_input().split())
    guards.append(((a, b), (c, d)))

for i, guard in enumerate(guards):
    a, b = guard
    if a[0] + b[0] <= k:
        print i + 1, a[0], k - a[0]
        break
    elif a[1] + b[1] <=k:
        print i + 1, a[1], k - a[1]
        break
    elif a[0] + b[1] <= k:
        print i + 1, a[0], k - a[0]
        break
    elif a[1] + b[0] <= k:
        print i + 1, a[1], k - a[1]
        break
else:
    print -1
