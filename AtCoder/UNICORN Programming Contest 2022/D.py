#coding=utf-8

n = int(raw_input())

ps = set()

for i in xrange(n):
    a, b = map(int, raw_input().split())
    ps.add((a, b))

visited = set()

def dfs(i, j):
    if (i, j) not in ps:
        return

    if (i, j) in visited:
        return

    visited.add((i, j))
    for (a, b) in [(i-1,j-1), (i-1,j), (i,j-1), (i,j+1), (i+1,j), (i+1,j+1)]:
        dfs(a, b)

res = 0
for (a, b) in ps:
    if (a, b) not in visited:
        dfs(a, b)
        res += 1
print res


'''
^^^^^^^^^^TEST^^^
6
-1 -1
0 1
0 2
1 0
1 2
2 0
------
3
$$$TEST$$$$

^^^^^TEST^^^^
4
5 0
4 1
-3 -4
-2 -5
-----
4
$$$TEST$$$$


^^^^^^^^^TEST^^^^
5
2 1
2 -1
1 0
3 1
1 -1
-------
1
$$$TEST$$$$

'''




