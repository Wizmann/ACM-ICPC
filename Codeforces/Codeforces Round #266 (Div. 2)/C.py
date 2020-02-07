# https://codeforces.com/problemset/problem/466/C

def solve(ns):
    n = len(ns)
    s = sum(ns)
    if s % 3 != 0:
        return 0
    s /= 3
    ps = ns[:]
    for i in range(1, n):
        ps[i] += ps[i - 1]

    def segsum(a, b):
        return ps[b] - (0 if a == 0 else ps[a - 1])

    ls = [0 for i in range(n)]
    rs = [0 for i in range(n)]

    for i in range(n):
        if segsum(0, i) == s:
            ls[i] += 1
        if i > 0:
            ls[i] += ls[i - 1]

    for i in range(n - 1, -1, -1):
        if segsum(i, n - 1) == s:
            rs[i] += 1
        if i < n - 1:
            rs[i] += rs[i + 1]

    res = 0
    for i in range(n - 2):
        if segsum(0, i) == s:
            res += rs[i + 2]
    return res

assert(solve([1, 2, 3, 0, 3]) == 2)
assert(solve([0, 1, -1, 0]) == 1)
assert(solve([4, 1]) == 0)
assert(solve([1, 1]) == 0)

n = int(input())
ns = list(map(int, input().split()))
print(solve(ns))
