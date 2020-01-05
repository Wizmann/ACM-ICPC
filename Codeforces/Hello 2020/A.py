n, m = map(int, raw_input().split())
 
ns = raw_input().split()
ms = raw_input().split()
 
q = int(raw_input())
 
for case_ in xrange(q):
    y = int(raw_input())
    y -= 1
    nn = y % n
    mm = y % m
 
    print ns[nn] + ms[mm]
