∂n = int(raw_input())
ns = sorted([int(raw_input()) for i in xrange(n)])

p, q, r = 0, 1, n - 1
flag = False

while p < n:
    q = p + 1
    r = n - 1
    while q < r:
        s = ns[p] + ns[q] + ns[r]
        if s < 0:
            q += 1
        elif s == 0:
            print ns[p], ns[q], ns[r]
            q += 1
            flag = True
        else:
            r -= 1
    p += 1

if not flag:
    print 'No Solution'
