import sys
 
def solve(x):
    cur = 9
    tot = 0
    while cur <= x:
        tot += 1
        cur = cur * 10 + 9
    return tot
 
T = int(raw_input())
 
for case_ in xrange(T):
    a, b = map(int, raw_input().split())
    vb = solve(b)
 
    print vb * a
