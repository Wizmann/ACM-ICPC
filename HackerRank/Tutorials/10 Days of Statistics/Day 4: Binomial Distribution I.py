def C(a, b):
    res = 1
    for i in xrange(a):
        res *= b - i
        res /= i + 1
    return res

#(a, b) = map(float, raw_input().split())
a, b = 1.09, 1
p = a / (a + b)
ans = 0.0
for i in xrange(3, 6 + 1):
    ans += C(i, 6) * (p ** i) * ((1 - p) ** (6 - i))
print '%.3f' % ans
