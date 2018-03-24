N = 12345

dp = [0 for i in xrange(N)]

dp[0] = 1

for coin in [1, 5, 10, 25, 50]:
    for i in xrange(20):
        u = coin * (1 << i)
        if u > N:
            break
        for j in xrange(N - 1, -1, -1):
            if dp[j] and j + u < N:
                dp[j + u] += dp[j]

import sys

for line in sys.stdin:
    print dp[int(line)]
