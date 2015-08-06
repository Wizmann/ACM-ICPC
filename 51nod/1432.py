(n, m) = map(int, raw_input().split())
ns = sorted([int(raw_input()) for i in xrange(n)])

p, q = 0, n - 1

ans = 0

while p < q:
    if ns[p] + ns[q] > m:
        q -= 1
    else:
        ans += 1
        p += 1
        q -= 1
print n - ans
