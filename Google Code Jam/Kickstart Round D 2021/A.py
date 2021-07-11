INF = 10 ** 20

from collections import defaultdict

def progression(items):
    return items[1] - items[0] == items[2] - items[1]

def check(a, c):
    if (a + c) % 2 == 0:
        return (a + c) / 2
    else:
        return INF

T = int(raw_input())

for case_ in xrange(T):
    mat = []
    for i in xrange(3):
        mat.append(map(int, raw_input().split()))
    mat[1] = [mat[1][0]] + [INF] + [mat[1][1]]

    cnt = 0

    if progression(mat[0]):
        cnt += 1
    if progression(mat[2]):
        cnt += 1
    if progression([mat[0][0], mat[1][0], mat[2][0]]):
        cnt += 1
    if progression([mat[0][2], mat[1][2], mat[2][2]]):
        cnt += 1

    d = defaultdict(int)

    d[check(mat[0][0], mat[2][2])] += 1
    d[check(mat[0][2], mat[2][0])] += 1
    d[check(mat[1][0], mat[1][2])] += 1
    d[check(mat[0][1], mat[2][1])] += 1

    if INF in d:
        del d[INF]

    print 'Case #%d: %d' % (case_ + 1, cnt + max(d.values()))

'''
^^^TEST^^^
3
3 4 11
10 9
-1 6 7
4 1 6
3 5
2 5 6
9 9 9
9 9
9 9 9
-------
Case #1: 4
Case #2: 3
Case #3: 8
$$$TEST$$$


^^^TEST^^^
1
1 10 100
1000 10000
100000 10000000 1000000000
-----
Case #1: 1
$$$TEST$$$


'''


