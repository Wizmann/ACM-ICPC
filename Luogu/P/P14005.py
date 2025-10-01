#python3
INF = 10 ** 10

raw_input = input
xrange = range

n = int(raw_input())

maxy = -1
minx = INF

for i in xrange(n):
    (x, y) = list(map(int, raw_input().split()))
    maxy = max(maxy, y)
    minx = min(minx, x)

print(minx, maxy + 1)

'''
^^^^TEST^^^^
4
1 1
1 2
2 1
2 2
-------
1 3
$$$$TEST$$$$$
'''

