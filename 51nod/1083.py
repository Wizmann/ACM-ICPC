n = int(raw_input())

mat = [map(int, raw_input().split()) for i in xrange(n)]
dp = [[0 for i in xrange(n)] for j in xrange(n)]

dp[0][0] = mat[0][0]
for i in xrange(n):
    for j in xrange(n):
        if i + 1 < n:
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + mat[i + 1][j])
        if j + 1 < n:
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + mat[i][j + 1])
print dp[n - 1][n - 1]
