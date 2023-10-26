import math

BASE = 10 ** 200

def do_solve(y):
    y *= BASE
    x = 1

    for i in xrange(12345):
        x1 = (x + y / x) / 2
        if x == x1:
            break
        x = x1

    assert x * x <= y

    return x

def solve(y):
    return sum(map(int, str(do_solve(y))[:100]))

assert solve(2) == 475

res = 0
for i in xrange(1, 100):
    u = int(math.sqrt(i))
    if u * u == i:
        continue
    res += solve(i)
print res
