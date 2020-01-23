import sys
import math
from collections import defaultdict
 
T = int(raw_input())
 
for case_ in xrange(T):
    (n, d) = map(int, raw_input().split())
    p = int(math.sqrt(d) - 1)
    l, r = max(0, p - 100), p + 100
 
    flag = (d <= n)
    for i in xrange(l, r + 1):
        t = i + ((d + i) / (i + 1))
        if t <= n:
            flag = True
            break
    if flag:
        print 'YES'
    else:
        print 'NO'
