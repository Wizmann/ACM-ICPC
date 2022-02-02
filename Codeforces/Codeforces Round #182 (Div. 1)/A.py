#coding=utf-8
INF = 10 ** 10

n = int(raw_input())
nums = map(int, raw_input().split())

ps = filter(lambda x: x >= 0, nums)
ns = filter(lambda x: x < 0, nums)

rem = len(ns) % n
ps = ps + map(lambda x : x * -1, ns)
res = sum(ps)
if n % 2 == 0 and rem % 2 == 1:
    res -= min(ps) * 2
print res

'''
^^^^TEST^^^
2
50 50 50
-----
150
$$$TEST$$$

^^^^TEST^^^^
2
-1 -100 -1
-----
100
$$$TEST$$$

^^^^TEST^^^^
2
-1 -100 -200
-----
299
$$$TEST$$$

^^^TEST^^^
3
-959 -542 -669 -513 160
------
2843
$$$TEST$$$
'''



