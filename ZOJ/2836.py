import sys

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)

inputs = [line for line in sys.stdin]
T = len(inputs)

for i in xrange(0, T, 2):
    n, m = map(int, inputs[i].split())
    ns = map(int, inputs[i + 1].split())

    res = 0

    for i in xrange(1, 1 << n):
        ms = [num for j, num in enumerate(ns) if (1 << j) & i]
        l = reduce(lcm, ms, 1)
        if len(ms) % 2 == 0:
            res -= m / l
        else:
            res += m / l
    print res

