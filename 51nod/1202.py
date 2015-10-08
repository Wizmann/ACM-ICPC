MOD = (10 ** 9) + 7

n = int(raw_input())
ns = map(int, [raw_input() for i in xrange(n)])

dp = [0 for i in xrange(n + 1)]
d = {}

for i, num in enumerate(ns):
    if num not in d:
        u = dp[i] + dp[i] + 1
        dp[i + 1] = u
    else:
        idx = d[num]
        u = dp[i] + dp[i] - dp[idx - 1]
        dp[i + 1] = u
    d[num] = i + 1
    dp[i + 1] %= MOD
    
print dp[-1]
