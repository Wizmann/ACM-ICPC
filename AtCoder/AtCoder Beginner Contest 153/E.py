INF = 10 ** 20
 
(h, n) = map(int, raw_input().split())
 
dp = [INF for i in xrange(h + 1)]
dp[0] = 0
 
for i in xrange(n):
    (a, b) = map(int, raw_input().split())
    for j in xrange(h + 1):
        if dp[j] >= INF:
            continue
        nxt = min(j + a, h)
        dp[nxt] = min(dp[nxt], dp[j] + b)
print dp[h]
