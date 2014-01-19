N = 200

dp = [0 for i in xrange(N + 5)]
dp[0] = 1

coins = [1, 2, 5, 10, 20, 50, 100, 200]

for item in coins:
    for i in xrange(N):
        if dp[i] and i + item <= N:
            dp[i + item] += dp[i]

print dp[N]
