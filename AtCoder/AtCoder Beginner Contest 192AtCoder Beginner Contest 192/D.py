def make_v(x, m):
    res = 0
    base = 1
    for i, u in enumerate(x):
        res += u * base
        base *= m
    return res

INF = 10 ** 20

x = map(int, list(raw_input()))[::-1]
m = int(raw_input())

u = max(x) + 1

l, r = u, INF

while l <= r:
    mm = (l + r) / 2
    v = make_v(x, mm)
    if v > m:
        r = mm - 1
    else:
        l = mm + 1

if r >= INF:
    print 1
else:
    print (r - u) + 1

'''
^^^TEST^^^
22
10
-----
2
$$$TEST$$$

^^^TEST^^^
22
9
-----
1
$$$TEST$$$

^^^TEST^^^
9
8
-----
0
$$$TEST$$$

^^^TEST^^^
1
8
-----
1
$$$TEST$$$

^^^TEST^^^
999
1500
------
3
$$$TEST$$$

^^^TEST^^^
100000000000000000000000000000000000000000000000000000000000
1000000000000000000
-----
1
$$$TEST$$$
'''
