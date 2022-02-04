MOD = (10 ** 9) + 7
INF = 10 ** 10

class Solution(object):
    def numberOfWays(self, corridor):
        n = len(corridor)
        seats = []
        for i in xrange(n):
            if corridor[i] == 'S':
                seats.append(i)
        if len(seats) < 2:
            return 0
        if len(seats) == 2:
            return 1
        if len(seats) % 2 != 0:
            return 0

        dp = [-INF for i in xrange(n)]

        dp[seats[1]] = 1
        m = len(seats)

        for i in xrange(3, m):
            a = seats[i - 2]
            b = seats[i - 1]
            c = seats[i]
            # print a, b, c

            dp[c] = dp[a] * (b - a) % MOD

        return dp[seats[-1]]

'''
^^^^TEST^^^
"SSPPSPS"
------
3
$$$TEST$$$

^^^^TEST^^^
"PPSPSP"
------
1
$$$TEST$$$

^^^^TEST^^^
"S"
------
0
$$$TEST$$$
'''
