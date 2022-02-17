#python3

T = int(input())

for case_ in range(T):
    n, m = map(int, input().split())
    ns = map(int, input().split())

    print('Case #%d: %d' % (case_ + 1, sum(ns) % m))

'''
^^^TEST^^^
2
7 3
1 2 3 4 5 6 7
5 10
7 7 7 7 7
------
Case #1: 1
Case #2: 5
$$$TEST$$$
'''


