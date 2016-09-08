#(k, n) = map(int, raw_input().split())
k, n = 12, 10

def C(a, b):
    res = 1
    for i in xrange(a):
        res *= b - i
        res /= 1 + i
    return res

def P(a, b):
    p = 1.0 * k / 100
    res = (p ** a) * ((1 - p) ** (b - a))
    return res

ans1 = C(0, 10) * P(0, 10) + C(1, 10) * P(1, 10) + C(2, 10) * P(2, 10)
ans2 = 1 - C(0, 10) * P(0, 10) - C(1, 10) * P(1, 10)

print "%.3f" % ans1
print "%.3f" % ans2
