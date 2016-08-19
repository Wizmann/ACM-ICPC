import math
def maxi(x):
    y = math.sqrt(x)
    return int(y)

def looper(x):
    d = {}
    y = maxi(x)
    if y * y == x:
        return 0
    d[(0, 1)] = 0
    a, b, step = y, 1, 1
    while True:
        if (a, b) in d:
            return step - d[(a, b)]
        d[(a, b)] = step
        b, a = (x - a * a) / b, a
        a = a - (y + a) / b * b
        a = -a
        step += 1


assert looper(13) == 5
assert looper(23) == 4
assert looper(7) == 4
assert looper(9) == 0

assert len([i for i in xrange(1, 13 + 1) if looper(i) % 2 == 1]) == 4

print len([i for i in xrange(1, 10000 + 1) if looper(i) % 2 == 1])
