#coding=utf-8

def dfs(cur, n, rem, ls):
    if cur == n:
        if rem == 1:
            return 1
        else:
            return 0

    res = 0
    for num in ls[cur]:
        if rem % num == 0:
            res += dfs(cur + 1, n, rem / num, ls)
    return res

n, x = map(int, raw_input().split())

ls = []

for i in xrange(n):
    ns = map(int, raw_input().split())[1:]
    ls.append(ns)

print dfs(0, n, x, ls)

'''
^^^^TEST^^^
2 40
3 1 8 4
2 10 5
-------
2
$$$TEST$$$

^^^^TEST^^^
3 200
3 10 10 10
3 10 10 10
5 2 2 2 2 2
-------
45
$$$TEST$$$

^^^^TEST^^^
3 1000000000000000000
2 1000000000 1000000000
2 1000000000 1000000000
2 1000000000 1000000000
-------
0
$$$TEST$$$
'''


