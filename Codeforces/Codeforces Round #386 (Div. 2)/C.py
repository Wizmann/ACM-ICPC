#coding=utf-8

INF = 10 ** 10

s, x1, x2 = map(int, raw_input().split())
t1, t2 = map(int, raw_input().split())
p, d = map(int, raw_input().split())

dis1 = abs(x1 - x2)
v1 = dis1 * t2

v2 = INF
if t1 >= t2:
    pass
else:
    dis2 = 0
    while p != x1:
        if p + d < 0 or p + d > s:
            d *= -1
        p += d
        dis2 += 1
    if (x2 - x1) * d >= 0:
        dis2 += abs(x2 - x1)
    else:
        if d < 0:
            dis2 += x1 * 2
        else:
            dis2 += (s - x1) * 2
        dis2 += abs(x2 - x1)
    v2 = dis2 * t1

res = min(v1, v2)
print res


'''
^^^^TEST^^^
4 2 4
3 4
1 1
-------
8
$$$TEST$$$

^^^TEST^^^^
5 4 0
1 2
3 1
-------
7
$$$TEST$$$

^^^TEST^^^
10 7 2
7 9
9 -1
-----
45
$$$TEST$$$
'''
