INF = 0x3f3f3f3f
(n, t, c) = map(int, raw_input().split())
ps = map(int, raw_input().split())
ps = [INF] + ps + [INF]
rs = [i for (i, v) in enumerate(ps) if v > t]
ans = 0

for i in xrange(1, len(rs)):
    x = rs[i] - rs[i - 1]
    if x < c:
        continue
    ans += x - c
    
print ans



