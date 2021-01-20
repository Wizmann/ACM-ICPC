def dissolve(n, m, d):
    if n in d:
        return d[n]
    if n == 0:
        return (0, 1)
    if n == 1:
        return (10 / m, 10 % m)
    (a1, a2) = dissolve(n / 2, m, d)
    (b1, b2) = dissolve(n - n / 2, m, d)

    (c1, c2) = ((a1 * b2 + a2 * b1 + (a2 * b2) / m) % m, (a2 * b2) % m)
    d[n] = (c1, c2)
    return (c1, c2)

def solve(n, m):
    d = {}
    (a1, a2) = dissolve(n, m, d)
    # print a1, a2
    return a1 % m

assert solve(2, 7) == 0
assert solve(1, 2) == 1
assert solve(1000000000000000000 , 9997) == 9015

(n, m) = map(int, raw_input().split())
print solve(n, m)
