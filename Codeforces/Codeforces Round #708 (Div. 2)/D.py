T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ts = map(int, raw_input().split())
    ss = map(int, raw_input().split())

    dp = [0 for i in xrange(n)]

    for i in xrange(n):
        for j in xrange(i - 1, -1, -1):
            if ts[i] == ts[j]:
                continue
            delta = abs(ss[i] - ss[j])
            dp[i], dp[j] = max(dp[i], dp[j] + delta), max(dp[j], dp[i] + delta)
    print max(dp)

'''
^^^TEST^^^
5
4
1 2 3 4
5 10 15 20
4
1 2 1 2
5 10 15 20
4
2 2 4 1
2 8 19 1
2
1 1
6 9
1
1
666
----
35
30
42
0
0
$$$TEST$$$
'''
