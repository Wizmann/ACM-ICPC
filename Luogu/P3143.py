# coding=utf-8
INF = 10 ** 10

def do_solve(ns, k):
    n = len(ns)
    dp = [0 for i in xrange(n)]
    p, q = 0, 0
    while p < n and q < n:
        while abs(ns[q] - ns[p]) > k:
            p += 1
        dp[q] = q - p + 1
        if q - 1 >= 0:
            dp[q] = max(dp[q], dp[q - 1])
        q += 1
    return dp

def solve(ns, k):
    ns.sort()
    n = len(ns)

    dp1 = do_solve(ns, k)
    dp2 = do_solve(ns[::-1], k)[::-1]
    # print ns
    # print dp1, dp2

    maxi = max(max(dp1), max(dp2))
    for i in xrange(n - 1):
        maxi = max(maxi, dp1[i] + dp2[i + 1])
    return maxi

# 写测试，讲究的就是有枣没枣打三杆子
assert solve([1, 2, 1000, 2, 2, 1000], 0) == 5
assert solve([10, 5, 1, 12, 9, 5, 14], 3) == 5
assert solve([1, 1000, 2], 1) == 3
assert solve([1, 1000, 2], 0) == 2
assert solve([1], 110) == 1

(n, k) = map(int, raw_input().split())

ns = []
for i in xrange(n):
    ns.append(int(raw_input()))

print solve(ns, k)
