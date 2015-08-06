n = int(raw_input())
bs = [int(raw_input()) for i in xrange(n)]

dp = [0, 0]
for i in xrange(1, n):
    maxi = bs[i - 1]
    mini = 1
    dp[0], dp[1] = (
        max(
            dp[0] + abs(bs[i] - maxi),
            dp[1] + abs(bs[i] - mini)
        ),
        max(
            dp[0] + abs(1 - maxi),
            dp[1] + abs(1 - mini)
        )
    )
print max(dp[0], dp[1])
