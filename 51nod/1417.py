def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

n = int(raw_input())
for i in xrange(n):
    (a, b) = map(int, raw_input().split())
    x = a + 3 * b
    y = 4 * (a + b)
    z = gcd(x, y)
    print '%d/%d' % (x / z, y / z)
