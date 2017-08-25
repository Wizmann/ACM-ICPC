n = int(raw_input())
ns = map(int, raw_input().split())

d = {}

for i in xrange(n):
    u = ns[i]
    d[u] = i
    
for i in xrange(n):
    u = d[i + 1]
    v = d[u + 1]
    print v + 1
