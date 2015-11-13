import math

n = int(raw_input())

ans = []
for i in xrange(n):
    if i * i >= n:
        break
    u = i * i
    v = n - u
    if u > v:
        break
    vv = int(math.sqrt(v) + 0.5)
    if vv * vv == v:
        ans.append((min(i, vv), max(i, vv)))

if not ans:
    print 'No Solution'
else:
    for (a, b) in ans:
        print a, b
