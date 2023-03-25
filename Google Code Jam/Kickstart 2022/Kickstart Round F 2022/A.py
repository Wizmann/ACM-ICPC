#python3
from functools import cmp_to_key

xrange = range

def cmp(a, b):
    return (a > b) - (a < b) 

class Fabric(object):
    def __init__(self, color, dur, idx):
        self.color = color
        self.dur = dur
        self.idx = idx

    def __str__(self):
        return '<%s, %d, %d>' % (self.color, self.dur, self.idx)

T = int(input())

def AdaCmp(f1, f2):
    if f1.color != f2.color:
        return cmp(f1.color, f2.color)
    return cmp(f1.idx, f2.idx)

def CharlesCmp(f1, f2):
    if f1.dur != f2.dur:
        return cmp(f1.dur, f2.dur)
    return cmp(f1.idx, f2.idx)

for case_ in range(T):
    n = int(input())

    fabrics = []
    for i in range(n):
        (c, d, u) = input().split()
        d = int(d)
        u = int(u)
        fabrics.append(Fabric(c, d, u))

    l1 = sorted(fabrics, key=cmp_to_key(AdaCmp))
    l2 = sorted(fabrics, key=cmp_to_key(CharlesCmp))

    cnt = 0
    for i in xrange(n):
        if l1[i].idx == l2[i].idx:
            cnt += 1

    print('Case #%d: %d' % (case_ + 1, cnt))

'''
^^^^^^^^^TEST^^^^
3
2
blue 2 1
yellow 1 2
2
blue 2 1
brown 2 2
1
red 1 1
-----------
Case #1: 0
Case #2: 2
Case #3: 1
$$$$$$$TEST$$$$$

^^^^^^^^^TEST^^^^
1
5
blue 1 2
green 1 4
orange 2 5
red 3 6
yellow 3 7
------------
Case #1: 5
$$$$$$TEST$$$
'''

