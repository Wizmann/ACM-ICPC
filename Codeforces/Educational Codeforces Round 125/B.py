#coding=utf-8

T = int(raw_input())

for case_ in xrange(T):
    n, B, x, y = map(int, raw_input().split())

    tot = 0
    cur = 0
    for i in xrange(n):
        if cur + x > B:
            cur -= y
        else:
            cur += x
        tot += cur
    print tot

'''
^^^^TEST^^^
3
5 100 1 30
7 1000000000 1000000000 1000000000
4 1 7 3
-----
15
4000000000
-10
$$$TEST$$$
'''


