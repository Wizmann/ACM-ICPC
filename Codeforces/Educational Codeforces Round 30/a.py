(n, k, x) = map(int, raw_input().split())
ns = sorted(map(int, raw_input().split()), reverse=True)

ans = 0
for i in xrange(n):
    if i < k:
        ans += min(ns[i], x)
    else:
        ans += ns[i]
print ans
