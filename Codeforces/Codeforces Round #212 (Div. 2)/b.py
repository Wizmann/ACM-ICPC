# Result: Nov 16, 2013 7:16:29 PM   Wizmann  B - Petya and Staircases    Python 2   Accepted    46 ms   404 KB
(n, m) = map(int, raw_input().split())
if m:
    dirties = sorted(map(int, raw_input().split()))
    
if not m:
    print 'YES'
elif (dirties[0] == 1 or dirties[-1] == n):
    print 'NO'
else:
    for i in xrange(m):
        p = dirties[i:i+3]
        if (len(p) != 3):
            continue
        else:
            if p[0] == p[1] - 1 == p[2] - 2:
                print 'NO'
                break
    else:
        print 'YES'
    
