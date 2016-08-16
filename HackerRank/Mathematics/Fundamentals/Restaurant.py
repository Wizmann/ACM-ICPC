def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

T = int(raw_input())
for case_ in xrange(T):
    (a, b) = map(int, raw_input().split())
    g = gcd(a, b)
    print a * b / g / g
