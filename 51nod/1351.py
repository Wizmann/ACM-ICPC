import sys
sys.stdin = open('input.txt')

def solve():
    (n, c, x) = map(int, raw_input().split())
    lows, highs = [], []
    for i in xrange(n):
        (low, high) = map(int, raw_input().split())
        lows.append(low)
        highs.append(high)
    lows.sort(reverse=True)
    highs.sort()
    
    l, r = 0, n - 1
    
    while l <= r:
        m = (l + r) >> 1
        u = sum(lows[:m])
        v = c - sum(highs[:n - m])        
        if u >= x or v >= x:
            r = m - 1
        else:
            l = m + 1
    print l

T = int(raw_input())

for case_ in xrange(T):
    solve()
