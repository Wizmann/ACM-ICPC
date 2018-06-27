(n, k) = map(int, raw_input().split())
ns = map(int, raw_input().split())

pres = []
pres.append((0, -1))
for i in xrange(n):
    pres.append((ns[i] + pres[-1][0], i))

ns = pres[:]
pres.sort(reverse=True)

for i in xrange(1, n + 1):
    _, pre = pres[i - 1]
    u, cur = pres[i]
    pres[i] = (u, min(pre, cur))

ans = -1
for (u, cur) in ns:
    v = u - k
    l, r = 0, n
    while l <= r:
        m = (l + r) >> 1
        if pres[m][0] >= v:
            l = m + 1
        else:
            r = m - 1
    if r == -1:
        continue
    pre = pres[r][1]

    if pre < cur:
        ans = max(ans, cur - pre)
print ans

