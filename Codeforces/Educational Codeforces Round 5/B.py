(n, m) = map(int, raw_input().split())

res = -1

for i in xrange(n):
    ns = map(int, raw_input().split())
    res = max(res, min(ns))
    
print res
