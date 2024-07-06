import sys
import copy
MOD = 998244353

n = -1
ns = []
for line in sys.stdin:
    if n == -1:
        n = int(line)
    else:
        ns += map(int, line.split())

assert len(ns) == n

res = 0
evens = 0
for i in xrange(n):
    if ns[i] % 2 == 0:
        evens += 1

res += pow(2, evens, MOD)
res -= 1 + evens + evens * (evens - 1) / 2
res = ((res % MOD) + MOD) % MOD

dp = [[0] * 3, [0] * 3, [0] * 3] # A1, A2, B
for i in xrange(n):
    cur = ns[i]
    nxt = copy.deepcopy(dp)
    if cur % 2 == 1:
        nxt[0][0] += 1
        nxt[1][0] += 1
        nxt[0][1] += dp[2][0]
        nxt[1][1] += dp[0][0]
        nxt[0][2] += dp[2][1] + dp[2][2]
        nxt[1][2] += dp[0][1] + dp[0][2]
    else:
        nxt[2][0] += 1
        nxt[2][1] += dp[1][0]
        nxt[2][2] += dp[1][1] + dp[1][2]
    for i in xrange(3):
        for j in xrange(3):
            nxt[i][j] %= MOD
    dp = nxt

res = (res + dp[0][2] + dp[1][2] + dp[2][2]) % MOD
print res

'''

^^^^TEST^^^^
3
1 2 3
-----------
1
$$$$TEST$$$$

^^^^TEST^^^^
5
2 8 2 6 4
-----------
16
$$$$TEST$$$$

^^^^TEST^^^^
5
5 7 1 3 5
-----------
0
$$$$TEST$$$$

^^^^TEST^^^^
11
3 1 4 1 5 9 2 6 5 3 6
-----------
386
$$$$TEST$$$$

^^^^TEST^^^^
54
2 1 1 1 1 2 1 2 2 2 2 1 1 1 2 1 1 2
2 1 2 2 2 2 2 2 2 1 1 1 2 2 1 1 1 1
2 2 1 1 2 2 2 2 2 1 1 1 2 2 1 2 1 1
-----------
0
$$$$TEST$$$$
'''
