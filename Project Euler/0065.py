def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

es = [2]

cnt = 1
while len(es) < 111:
    es += [1, cnt * 2, 1]
    cnt += 1

def solve(k):
    a, b = 1, es[k]
    for i in xrange(k, 0, -1):
        c = es[i - 1]
        a += b * c
        g = gcd(a, b)
        a /= g
        b /= g
        a, b = b, a

    return (b, a)

assert solve(1) == (3, 1)
assert solve(2) == (8, 3)
assert solve(3) == (11, 4)
assert solve(9) == (1457, 536)
assert sum(map(int, list(str(solve(9)[0])))) == 17

print sum(map(int, list(str(solve(99)[0]))))
