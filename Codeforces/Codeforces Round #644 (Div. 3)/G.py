#coding=utf-8

T = int(raw_input())

for case_ in xrange(T):
    n, m, a, b = map(int, raw_input().split())

    board = [ [0 for j in xrange(m)] for i in xrange(n) ]


    if n * a != m * b:
        print 'NO'
        continue

    p = 0
    for i in xrange(n):
        for j in xrange(a):
            board[i][p] = 1
            p = (p + 1) % m

    print 'YES'
    for line in board:
        print ''.join(map(str, line))

'''
^^^TEST^^^^
5
3 6 2 1
2 2 2 1
2 2 2 2
4 4 2 2
2 1 1 2
-----------
YES
010001
100100
001010
NO
YES
11
11
YES
1100
1100
0011
0011
YES
1
1
$$$TEST$$$

^^^TEST^^^
2
22 25 1 11
22 31 19 11
----
NO
NO
$$$TEST$$$

^^^TEST^^^
1
17 17 13 13
---
x
$$$TEST$$$
'''


