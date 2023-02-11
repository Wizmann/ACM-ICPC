INF = 10 ** 100

def solve(n, s, ns):
    dp = [[INF, INF] for i in xrange(n)]
    minmax = []

    for i in xrange(n):
        if ns[i] <= s:
            a, b = 0, ns[i]
        elif ns[i] <= 2 * s:
            a, b = ns[i] - s, s
        else:
            a, b = s, ns[i] - s

        a, b = min(a, b), max(a, b)
        minmax.append((a, b))

    # print minmax

    dp[0][0] = ns[0] * minmax[1][0]
    dp[0][1] = ns[0] * minmax[1][1]
    for i in xrange(1, n - 1):
        a0, b0 = minmax[i]
        a1, b1 = minmax[i + 1]

        if i + 1 == n - 1:
            a1, b1 = ns[-1], ns[-1]

        dp[i][0] = min(dp[i - 1][0] + b0 * a1, dp[i - 1][1] + a0 * a1)
        dp[i][1] = min(dp[i - 1][0] + b0 * b1, dp[i - 1][1] + a0 * b1)

        # print dp[i]

    return min(dp[n - 2])

T = int(raw_input())

for case_ in xrange(T):
    n, s = map(int, raw_input().split())
    ns = map(int, raw_input().split())

    print solve(n, s, ns)


'''
^^^^TEST^^^^
1
5 1
5 3 4 3 5
-------
18
$$$TEST$$$$


^^^TEST^^^^^
10
5 0
2 0 1 3 4
5 1
5 3 4 3 5
7 2
7 6 5 4 3 2 1
5 1
1 2 3 4 5
5 2
1 2 3 4 5
4 0
0 1 1 1
5 5
4 3 5 6 4
4 1
0 2 1 0
3 99999
200000 200000 200000
6 8139
7976 129785 12984 78561 173685 15480
-------------
0
18
32
11
14
0
16
0
40000000000
2700826806
$$$TEST$$$


'''
