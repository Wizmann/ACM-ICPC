import sys

n = int(raw_input())
ns = [int(raw_input()) for i in xrange(n)]
d = {}

for i in xrange(n):
    for j in xrange(i + 1, n):
        s = ns[i] + ns[j]
        if s not in d:
            d[s] = []
        d[s].append((i, j))
        
for (key, vlist1) in d.items():
    vlist2 = d.get(-key, [])
    for a in vlist1:
        for b in vlist2:
            if len(set(list(a) + list(b))) == 4:
                print 'Yes'
                sys.exit(0)
print 'No'
