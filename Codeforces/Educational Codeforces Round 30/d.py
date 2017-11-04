d = { 1: set([1]) }

def dfs(n):
    if n in d:
        return d[n]
    a, b = n / 2, (n + 1) / 2
    c = set([1])
    for item in dfs(a):
        for jtem in dfs(b):
            c.add(item + jtem + 1)
    d[n] = c
    return d[n]

def solve(n, k, l, r):
    if k == 1:
        return range(l, r + 1)

    k -= 1
    if k % 2 != 0:
        return [-1]

    a, b = n / 2, (n + 1) / 2
    if k <= a * 2 - 1:
        return solve(a, k - 1, r - a + 1, r) + solve(b, 1, l, l + b - 1)
    elif a * 2 - 1 + b * 2 - 1 >= k:
        return solve(a, a * 2 - 1 , r - a + 1, r) + solve(b, k - (a * 2 - 1), l, l + b - 1)

    return [-1]

(n, k) = map(int, raw_input().split())

print ' '.join(map(str, solve(n, k, 1, n)))
