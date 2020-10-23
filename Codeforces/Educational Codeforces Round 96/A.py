#coding=utf-8

N = 1111

ns = [(0, 0, 0) for i in xrange(N)]

ns[3] = (1, 0, 0)
ns[5] = (0, 1, 0)
ns[7] = (0, 0, 1)

for i in xrange(N):
    if ns[i] == (0, 0, 0):
        continue
    a, b, c = ns[i]
    if i + 3 < N:
        ns[i + 3] = (a + 1, b, c)
    if i + 5 < N:
        ns[i + 5] = (a, b + 1, c)
    if i + 7 < N:
        ns[i + 7] = (a, b, c + 1)

T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    if ns[n] == (0, 0, 0):
        print -1
    else:
        a, b, c = ns[n]
        print a, b, c


'''
^^^TEST^^^
4
30
67
4
14
---
2 2 2
7 5 3
-1
0 0 2
$$$TEST$$$
'''

