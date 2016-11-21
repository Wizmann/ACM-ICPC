n = int(raw_input())

ns = []
tl, tr = 0, 0
for i in xrange(n):
    (l, r) = map(int, raw_input().split())
    ns.append((l, r))
    tl += l
    tr += r

ans = -1
maxi = abs(tl - tr)

for i, (l, r) in enumerate(ns):
    cur = abs(tl - tr + r + r - l - l)
    if cur > maxi:
        ans = i
        maxi = cur

print ans + 1
