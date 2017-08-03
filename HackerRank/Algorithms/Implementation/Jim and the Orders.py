n = int(raw_input())
ns = []
for i in xrange(n):
    u, d = map(int, raw_input().split())
    ns.append(u + d)

print ' '.join(map(lambda (i, n): str(i + 1), sorted(enumerate(ns), key=lambda x: x[1])))
