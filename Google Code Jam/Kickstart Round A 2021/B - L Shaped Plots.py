#coding=utf-8

def do_solve(n, m, board):
    con_y = [ [0 for j in xrange(m)] for i in xrange(n) ]
    con_x = [ [0 for j in xrange(m)] for i in xrange(n) ]

    for i in xrange(n):
        pre = 0
        for j in xrange(m - 1, -1, -1):
            if board[i][j] == 0:
                pre = 0
            else:
                pre += 1
            con_y[i][j] = pre

    for j in xrange(m):
        pre = 0
        for i in xrange(n - 1, -1, -1):
            if board[i][j] == 0:
                pre = 0
            else:
                pre += 1
            con_x[i][j] = pre

    res = 0
    for i in xrange(n):
        for j in xrange(m):
            xx = con_x[i][j]
            yy = con_y[i][j]


            if xx < 2 or yy < 2:
                continue

            # print xx, yy, min(xx, yy / 2), min(xx / 2, yy)

            res += min(xx, yy / 2) - 1
            res += min(xx / 2, yy) - 1
    return res

def solve(n, m, board):
    res = 0
    res += do_solve(n, m, board)

    for i in xrange(n):
        board[i] = board[i][::-1]
    res += do_solve(n, m, board)

    for j in xrange(m):
        l, r = 0, n - 1
        while l < r:
            board[l][j], board[r][j] = board[r][j], board[l][j]
            l += 1
            r -= 1
    res += do_solve(n, m, board)

    for i in xrange(n):
        board[i] = board[i][::-1]
    res += do_solve(n, m, board)
    return res

T = int(raw_input())

for case_ in xrange(T):
    r, c = map(int, raw_input().split())
    board = []
    for i in xrange(r):
        line = map(int, raw_input().split())
        board.append(line)

    print 'Case #%d: %d' % (case_ + 1, solve(r, c, board))

'''
^^^^TEST^^^
2
4 3
1 0 0
1 0 1
1 0 0
1 1 0
6 4
1 0 0 0
1 0 0 1
1 1 1 1
1 0 1 0
1 0 1 0
1 1 1 0
------
Case #1: 1
Case #2: 9
$$$TEST$$$


^^^TEST^^^
1
4 3
0 1 0
0 1 0
1 1 1
0 1 0
---
Case #1: 0
$$$TEST$$$

^^^TEST^^^
1
5 3
0 1 0
0 1 0
0 1 1
0 1 0
0 1 1
---
Case #1: 1
$$$TEST$$$

^^^TEST^^^
1
5 6
1 0 0 0 0 0
1 0 0 0 0 0
1 1 0 0 0 0
1 0 0 0 0 0 
1 1 1 1 1 1
---
Case #1: 3
$$$TEST$$$

^^^TEST^^^
2
4 3
1 0 0
1 0 1
1 0 0
1 1 0
6 4
1 0 0 0
1 0 0 1
1 1 1 1
1 0 1 0
1 0 1 0
1 1 1 0
----
Case #1: 1
Case #2: 9
$$$TEST$$$


'''

