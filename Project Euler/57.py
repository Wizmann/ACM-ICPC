from fractions import gcd

a = 3
b = 2

ans = 0
for i in xrange(999):
    a = a + b
    a, b = b, a
    a = a + b
    c = gcd(a, b)
    a /= c
    b /= c
    if len(str(a)) > len(str(b)):
        ans += 1

print ans
