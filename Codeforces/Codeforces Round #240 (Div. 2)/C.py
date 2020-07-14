n, k = map(int, raw_input().split())

m = n / 2
t = k - (m - 1)

if n == 1 and k == 0:
    print 19,
elif n == 1 or t <= 0:
    print -1
else:
    print t, 2 * t,
    
    idx = 1
    for i in xrange(m):
        while True:
            a, b = idx, idx + 1
            idx += 2
            if [a, b] != [t, 2 * t]:
                break;
        if i == m - 1:
            if n % 2:
                print a,
        else:
            print a, b,
            

