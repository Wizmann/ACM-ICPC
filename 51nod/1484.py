(n, q) = map(int, raw_input().split())

x0, x1 = 1 << (n - 1), (1 << n) - 1
l = []
for i in xrange(q):
    (a, b, c, d) = map(int, raw_input().split())
    while a < n:
        b = b * 2 
        c = c * 2 + 1
        a += 1
    if d:
        l.append((b, 1))
        l.append((c, -1))
    else:
        if x0 <= b - 1:
            l.append((x0, 1))
            l.append((b - 1, -1))
        if x1 >= c + 1:
            l.append((c + 1, 1))
            l.append((x1, -1))
            
l.append((x0, 1))
l.append((x1, -1))
l.sort(cmp=lambda x, y: cmp(y[1], x[1]) if x[0] == y[0] else cmp(x, y))

#print l

cnt = 0
pre = x0
tot = 0
for item in l:
    if cnt == q + 1:
        tot += item[0] - pre + 1
        if tot > 1:
            break
    cnt += item[1]
    if cnt == q + 1:
        pre = item[0]
    
if tot == 0:
    print 'Game cheated!'
elif tot > 1:
    print 'Data not sufficient!'
else:
    print pre
