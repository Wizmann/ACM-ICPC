INF = 10 ** 100
N = 10

board = []
for i in xrange(N):
    board.append(raw_input())

minx, maxx = INF, -INF
miny, maxy = INF, -INF
for i in xrange(N):
    for j in xrange(N):
        if board[i][j] == '#':
            minx = min(minx, j)
            miny = min(miny, i)
            maxx = max(maxx, j)
            maxy = max(maxy, i)

print miny + 1, maxy + 1
print minx + 1, maxx + 1

'''
^^^^^^TEST^^^
..........
..........
..........
..........
...######.
...######.
...######.
...######.
..........
..........
---------------
5 8
4 9
$$$TEST$$$

^^^^TEST^^^
..........
..#.......
..........
..........
..........
..........
..........
..........
..........
..........
------
2 2
3 3
$$$$TEST$$$

^^^^TEST^^^
##########
##########
##########
##########
##########
##########
##########
##########
##########
##########
--------
1 10
1 10
$$$TEST$$$


'''
