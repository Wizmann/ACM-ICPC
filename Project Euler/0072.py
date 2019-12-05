import sys
import itertools

N = 10 ** 6

dp = [0 for i in xrange(N + 1)]

def getFi(x):
    if dp[x] == 0:
        return x - 1
    y = 1
    mod = dp[x]
    cnt = 0
    while x % mod == 0:
        y *= mod
        x /= mod
        cnt += 1
    if x == 1:
        return (mod - 1) * (mod ** (cnt - 1))
    return getFi(x) * getFi(y)

tot = 0
for i in xrange(2, N + 1):
    fi = getFi(i)
    tot += fi

    if dp[i] == 0:
        j = 2
    while i * j <= N:
        dp[i * j] = i
        j += 1
print tot
