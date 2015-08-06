n = int(raw_input())
ns = [raw_input() for i in xrange(n)]

ans = ''.join(sorted(ns, cmp=lambda x, y: cmp(int(x + y), int(y + x))))
l = len(ans)

for i in xrange(0, l, 1000):
    print ''.join(ans[i: i + 1000])
