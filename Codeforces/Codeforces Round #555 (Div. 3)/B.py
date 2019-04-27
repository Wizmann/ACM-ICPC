n = int(raw_input())
ns = map(int, raw_input())
d = {}

ms = map(int, raw_input().split())
for i in xrange(1, 10):
    d[i] = ms[i - 1]

gt = False
for i in xrange(n):
    #print i, d[ns[i]], ns[i], gt
    if d[ns[i]] > ns[i]:
        ns[i] = max(ns[i], d[ns[i]])
        gt = True
    elif d[ns[i]] == ns[i] and gt:
        pass
    else:
        if gt:
            break

print ''.join(map(str, ns))
