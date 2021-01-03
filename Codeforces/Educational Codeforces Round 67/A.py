def solve(n, s, t):
    both = (s + t) - n
    l = s - both
    r = t - both
    return max(l, r) + 1

assert solve(12, 2, 10) == 11
assert solve(10, 1, 10) == 10
assert solve(10, 9, 10) == 2
assert solve(10, 9, 9) == 2
assert solve(10, 1, 2) == 10
assert solve(10, 5, 7) == 6
assert solve(10, 10, 10) == 1
assert solve(2, 1, 1) == 2
assert solve(10, 5, 5) == 6

T = int(raw_input())

for case_ in xrange(T):
    (n, s, t) = map(int, raw_input().split())
    print solve(n, s, t)

