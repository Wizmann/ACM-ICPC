import sys
sys.setrecursionlimit(23456)


T = int(raw_input())

def dfs(l, r):
    r -= l - 1
    l = 1
    if l == r:
        return 0

    if (l + r) % 2 == 1:
        return 0

    mid = (l + r) / 2
    return 1 + dfs(l, mid) * 2


for case_ in xrange(T):
    n, a, d = map(int, raw_input().split())

    if d % 2 == 1:
        print 0
    else:
        print dfs(a, a + d) * (n - 1)

'''
^^^^TEST^^^
4
3 1 1
2 2 2
11 1 2
11 1 24
-----
0
1
10
70
$$$TEST$$$

^^^^TEST^^^
14
11 1 2
11 1 4
11 1 6
11 1 8
11 1 10
11 1 12
11 1 14
11 1 16
11 1 18
11 1 20
11 1 22
11 1 24
11 1 26
11 1 28
-----
10
30
10
70
10
30
10
150
10
30
10
70
10
30
$$$TEST$$$

^^^TEST^^^
1
123456789 -123456789 0
----
<TLE>
$$$TEST$$$


'''
