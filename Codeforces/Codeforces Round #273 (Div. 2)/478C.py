def solve(a, b, c):
    a, b, c = sorted([a, b, c], reverse=True)
    if a >= 2 * b + 2 * c:
        return b + c

    u = (2 * (b + c) - a) / 3
    res = u + (a - u) / 2
    return res

d = {}

def brute_force(a, b, c):
    a, b, c = sorted([a, b, c], reverse=True)
    key = (a, b, c)
    if key in d:
        return d[key]

    if a + b + c < 3:
        return 0

    maxi = 0
    if a >= 2 and b >= 1:
        maxi = max(maxi, brute_force(a - 2, b - 1, c) + 1)
    if a >= 2 and c >= 1:
        maxi = max(maxi, brute_force(a - 2, b, c - 1) + 1)
    if b >= 2 and c >= 1:
        maxi = max(maxi, brute_force(a, b - 2, c - 1) + 1)
    if a >= 1 and b >= 1 and c >= 1:
        maxi = max(maxi, brute_force(a - 1, b - 1, c - 1) + 1)
    d[key] = maxi
    return maxi

assert solve(5, 4, 3) == 4
assert solve(1, 1, 1) == 1
assert solve(2, 3, 3) == 2
assert solve(3, 5, 8) == brute_force(3, 5, 8)
assert solve(4, 5, 8) == brute_force(4, 5, 8)

'''
for i in xrange(100):
    for j in xrange(100):
        for k in xrange(100):
            assert solve(i, j, k) == brute_force(i, j, k)
'''


a, b, c = map(int, raw_input().split())
print solve(a, b, c)