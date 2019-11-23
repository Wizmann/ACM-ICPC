INF = 10 ** 10
 
n = int(raw_input())
ns = [INF] + map(int, raw_input().split())
 
maxi = (-1, -1)
 
mini = min(ns)
 
for i in xrange(1, 10):
    u = i
    r = n - ns[i]
    if r < 0:
        continue
    v = r / mini
 
    maxi = max(maxi, (v, u))
 
uu = -1
for i in xrange(9, 0, -1):
    if ns[i] == mini:
        uu = i
        break
 
res = str(maxi[1]) + (str(uu) * maxi[0])
if res == '-1':
    print -1
else:
    res = list(res)
    rem = n
    for c in res:
        c = int(c)
        rem -= ns[c]
 
    #print res, rem
    m = len(res)
    for i in xrange(1, m):
        c = int(res[i])
        for j in xrange(9, c, -1):
            if ns[j] - ns[c] <= rem:
                res[i] = str(j)
                rem = rem + ns[c] - ns[j]
                break
    print ''.join(res)
