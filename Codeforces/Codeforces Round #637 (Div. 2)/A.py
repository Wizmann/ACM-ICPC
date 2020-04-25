def solve(n, a, b, c, d):
    L, R = c - d, c + d
    
    l, r = (a - b) * n, (a + b) * n

    # print l, r
    # print L, R
    if r < L or l > R:
        return False
    return True

assert solve(7, 20, 3, 101, 18) == True
assert solve(11, 11, 10, 234, 2) == False

T = int(raw_input())
for case_ in xrange(T):
    (n, a, b, c, d) = map(int, raw_input().split())
    print 'Yes' if solve(n, a, b, c, d) else 'No'
