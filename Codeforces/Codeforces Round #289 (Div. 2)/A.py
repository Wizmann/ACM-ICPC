n = int(raw_input())
g = [[1 for i in xrange(n)] for j in xrange(n)]

for i in xrange(1, n):
    for j in xrange(1, n):
        g[i][j] = g[i - 1][j] + g[i][j - 1]

print g[n - 1][n - 1]
