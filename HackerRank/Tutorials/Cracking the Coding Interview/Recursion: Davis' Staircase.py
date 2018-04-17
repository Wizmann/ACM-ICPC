s = int(raw_input().strip())
for a0 in xrange(s):
    n = int(raw_input().strip())
    dp = [0 for i in xrange(n + 1)]
    dp[0] = 1
    
    for i in xrange(n):
        for j in [1, 2, 3]:
            if i + j <= n:
                dp[i + j] += dp[i]
    print dp[n]
