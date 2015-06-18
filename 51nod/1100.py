n = int(raw_input())

ns = sorted([map(int, raw_input().split()) + [i + 1] for i in xrange(n)], 
        key = lambda x: x[0])

INF = 0xdeadbeefdeadbeef
maxi = 0
res = []

for i in xrange(n - 1):
    delta_x = ns[i][0] - ns[i + 1][0]
    delta_y = ns[i][1] - ns[i + 1][1]
    (a, b) = ns[i][2], ns[i + 1][2]
    
    if delta_x == 0:
        k = INF
    else:
        k = delta_y / delta_x
    
    if k > maxi:
        maxi = k
        res = [(a, b)]
    elif k == maxi:
        res.append((a, b))

for item in res:
    print ' '.join(map(str, item))
