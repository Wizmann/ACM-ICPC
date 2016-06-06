import sys

lines = map(int, [line for line in sys.stdin])
n, ns = lines[0], lines[1:]

dp = [1 for i in xrange(n)]

for i in xrange(n):
    if i and ns[i] > ns[i - 1]:
        dp[i] = max(dp[i], dp[i - 1] + 1)

for i in xrange(n - 1, -1, -1):
    if i + 1 < n and ns[i] > ns[i + 1]:
        dp[i] = max(dp[i], dp[i + 1] + 1)
    
#print dp
print sum(dp)
