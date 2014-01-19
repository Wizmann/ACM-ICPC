def C(a, b):
    c = 1
    for i in xrange(a):
        c *= b - i
        c /= i + 1
    return c


ALL = 40
CHOICE = 20

print C(20, 40)
