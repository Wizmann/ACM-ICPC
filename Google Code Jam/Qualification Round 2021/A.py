#coding=utf-8

INF = 10 ** 10

def solve(a, b, s):
    n = len(s)
    dp = [ [INF for j in xrange(n)] for i in xrange(2) ]

    def get_dp(y, x):
        if x < 0:
            return 0
        return dp[y][x]

    for i in xrange(n):
        if s[i] == 'C':
            if i == 0:
                dp[0][i] = 0
            else:
                dp[0][i] = min(get_dp(0, i - 1), get_dp(1, i - 1) + b)
        elif s[i] == 'J':
            if i == 0:
                dp[1][i] = 0
            else:
                dp[1][i] = min(get_dp(1, i - 1), get_dp(0, i - 1) + a)
        else:
            assert s[i] == '?'
            if i == 0:
                dp[0][i] = 0
                dp[1][i] = 0
            else:
                dp[0][i] = min(get_dp(0, i - 1), get_dp(1, i - 1) + b)
                dp[1][i] = min(get_dp(1, i - 1), get_dp(0, i - 1) + a)
    return min(dp[0][n - 1], dp[1][n - 1])

T = int(raw_input())

for case_ in xrange(T):
    a, b, s = raw_input().split()
    a = int(a)
    b = int(b)

    print 'Case #%d: %d' % (case_ + 1, solve(a, b, s))

'''
^^^TEST^^^
4
2 3 CJ?CC?
4 2 CJCJ
1 3 C?J
2 5 ??J???
------
Case #1: 5
Case #2: 10
Case #3: 1
Case #4: 0
$$$TEST$$$

^^^TEST^^^
1
2 -5 ??JJ??
----
Case #1: -8
$$$TEST$$$

^^^TEST^^^
1
2 -5 C
----
Case #1: 0
$$$TEST$$$

'''



