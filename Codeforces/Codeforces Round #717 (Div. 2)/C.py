n = int(raw_input())
ns = map(int, raw_input().split())

tot = sum(ns)
flag = False

if tot % 2 == 0:
    MAXI = tot / 2
    dp = [0 for i in xrange(MAXI + 1)]
    dp[0] = 1

    for num in ns:
        for i in xrange(tot + 1, -1, -1):
            if i + num <= MAXI and dp[i]:
                dp[i + num] = 1
    if dp[MAXI]:
        flag = True

if not flag:
    print 0
else:
    base = 1
    res = -1
    while True:
        for i in xrange(n):
            if ns[i] / base % 2 == 1:
                res = i
                break
        if res == -1:
            base *= 2
        else:
            break
    print 1
    print res + 1

'''
^^^^TEST^^^
4
6 3 9 12
------
1
2
$$$TEST$$$

^^^^TEST^^^^
2
1 2
-----
0
$$$TEST$$$
'''



