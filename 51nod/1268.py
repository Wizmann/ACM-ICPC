(n, k) = map(int, raw_input().split())
ns = [int(raw_input()) for i in xrange(n)]

a = ns[:10]
b = ns[10:]
len_a, len_b = len(a), len(b)
sa, sb = set([]), set([])

for i in xrange(1 << len_a):
    s = 0
    for j in xrange(len_a):
        if (i & (1 << j)):
            s += a[j]
    sa.add(s)
    
for i in xrange(1 << len_b):
    s = 0
    for j in xrange(len_b):
        if (i & (1 << j)):
            s += b[j]
    sb.add(s)
    
for item in sa:
    u = k - item
    if u in sb:
        print 'Yes'
        break
else:
    print 'No'
