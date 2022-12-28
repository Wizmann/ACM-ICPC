#python3
raw_input = input
xrange = range

MAXN = 12345

while True:
    n, k, m = map(int, raw_input().split())
    if n + k + m == 0:
        break

    dp = [0 for i in xrange(n)]

    for i in xrange(1, n):
        dp[i] = (dp[i - 1] + k) % i

    print((dp[n - 1] + m) % n + 1)



'''
^^^^TEST^^^^
8 5 3
100 9999 98
10000 10000 10000
0 0 0
---------
1
93
2019
$$$TEST$$$
'''
