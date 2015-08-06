def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def solve():
    (a, b, c, d) = map(int, raw_input().split())
    
    g1 = gcd(a, b)
    g2 = gcd(c, d)
    return g1 == g2

T = int(raw_input())
for i in xrange(T):
    print 'Yes' if solve() else 'No'
