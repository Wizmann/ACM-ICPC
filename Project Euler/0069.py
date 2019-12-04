import sys
import itertools

N = 1000000

dp = [0 for i in xrange(N + 1)]

maxp = 0
maxi = 0

def getFi(x):
    if dp[x] == 0:
        return x - 1
    y = 1
    xx = x
    mod = dp[x]
    cnt = 0
    while x % mod == 0:
        y *= mod
        x /= mod
        cnt += 1
    if x == 1:
        return (mod - 1) * (mod ** (cnt - 1))
    return getFi(x) * getFi(y)

for i in xrange(2, N):
    fi = getFi(i)
    p = 1.0 * i / fi
    #print i, fi, p, dp[i]

    if p > maxp:
        maxi = i
        maxp = p

    if dp[i] == 0:
        j = 2
        while i * j <= N:
            dp[i * j] = i
            j += 1
print maxp, maxi
