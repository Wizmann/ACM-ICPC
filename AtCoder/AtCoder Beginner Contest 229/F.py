#coding=utf-8

INF = 10 ** 10

n = int(raw_input())

A = map(int, raw_input().split())
B = map(int, raw_input().split())

res = sum(B)

dp = [A[0], INF]

# center is A, first is A
for i in xrange(1, n):
    extra = 0
    if i == n - 1:
        extra = B[-1]

    a = min(dp[0] + A[i] + B[i - 1] + extra, dp[1] + A[i] + extra)
    b = min(dp[0], dp[1] + B[i - 1])
    dp = [a, b]

res = min(res, dp[0], dp[1])

dp = [INF, 0]

# center is A, first is B
for i in xrange(1, n):
    extra = 0
    if i == n - 1:
        extra = B[-1]

    a = min(dp[0] + A[i] + B[i - 1], dp[1] + A[i])
    b = min(dp[0] + extra, dp[1] + B[i - 1] + extra)
    dp = [a, b]
    # print dp

res = min(res, dp[0], dp[1])

print res

'''
^^^TEST^^^
5
31 4 159 2 65
5 5 5 5 10
------
16
$$$TEST$$$$

^^^TEST^^^
4
100 100 100 1000000000
1 2 3 4
------
10
$$$TEST$$$$
'''



