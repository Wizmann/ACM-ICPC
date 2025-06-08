def solve(a, b):
    res = 0
    if b == 1:
        return a
    while a:
        if a % b:
            res += a % b
            a -= a % b
        if a:
            a /= b
            res += 1
    return res

assert solve(59, 3) == 8
assert solve(2, 1) == 2
assert solve(2, 2) == 2
assert solve(3, 2) == 3
assert solve(1000000000000000000, 10) == 19

T = int(raw_input())
for case_ in xrange(T):
    (a, b) = map(int, raw_input().split())
    print solve(a, b)
