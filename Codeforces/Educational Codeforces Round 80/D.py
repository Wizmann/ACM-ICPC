import sys
from collections import defaultdict
 
MAXI = 1234567890
 
n, m = map(int, raw_input().split())
A = []
 
for i in xrange(n):
    A.append(map(int, raw_input().split()))
 
d = defaultdict(list)
 
for i in xrange(1 << m):
    for j in xrange(1 << m):
        if i | j == ((1 << m) - 1):
            d[i].append(j)
 
l, r = 0, MAXI
 
res = (-1, -1)
maxi = -1
 
while l <= r:
    mid = (l + r) >> 1
    dd = {}
    for i, nums in enumerate(A):
        t = 0
        for num in nums:
            t = t << 1
            if num >= mid:
                t += 1
        dd[t] = i
 
    flag = False
    for k1 in dd.keys():
        for k2 in d[k1]:
            if k2 in dd:
                if mid > maxi:
                    res = (dd[k1], dd[k2])
                    maxi = mid
                flag = True
                break
        if flag:
            break
 
    if flag:
        l = mid + 1
    else:
        r = mid - 1
 
print res[0] + 1, res[1] + 1
