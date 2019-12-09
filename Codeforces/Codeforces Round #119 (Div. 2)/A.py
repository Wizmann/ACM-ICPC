INF = 10 ** 10

def solve(n, a, b, c):
    dp = [-1 for i in xrange(n + 1)]
    dp[0] = 0
    for num in [a, b, c]:
        for i in xrange(n):
            if dp[i] >= 0 and i + num <= n:
                dp[i + num] = max(dp[i] + 1, dp[i + num])
    return dp[n]

assert solve(100, 23, 15, 50) == 2
assert solve(5, 5, 3, 2) == 2
assert solve(7, 5, 5, 2) == 2

(n, a, b, c) = map(int, raw_input().split())
print solve(n, a, b, c)
