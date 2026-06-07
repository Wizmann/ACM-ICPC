n, q = map(int, raw_input().split())

ns = map(int, raw_input().split())

res = 0
for i in xrange(n - 1):
    a, b = ns[i], ns[i + 1]
    ns[i] = ((b - a) % 5 + 5) % 5
    
res = sum(ns[:n - 1])
for q_ in xrange(q):
    l, r = map(int, raw_input().split())
    l -= 1
    r -= 1
    if l > 0:
        before = ns[l - 1]
        ns[l - 1] = (ns[l - 1] + 1) % 5
        res = res - before + ns[l - 1]
    if r < n - 1:
        before = ns[r]
        ns[r] = (ns[r] + 4) % 5
        res = res - before + ns[r]
    print res
    
