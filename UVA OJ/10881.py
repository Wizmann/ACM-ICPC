#python3

from collections import Counter, defaultdict

'''LONG LIVE PYTHON2'''
raw_input = input
xrange = range
__map = map
map = lambda func, ns: list(__map(func, ns))
__filter = filter
filter = lambda func, ns: list(__filter(func, ns))
'''LONG LIVE PYTHON2'''

class Ant(object):
    def __init__(self, pos, d, idx):
        self.pos = pos
        self.d = d
        self.idx = idx

T = int(raw_input())

for case_ in xrange(T):
    print('Case #%d:' % (case_ + 1))

    l, t, n = map(int, raw_input().split())

    ants = []
    for i in xrange(n):
        p, d = raw_input().split()
        p = int(p)
        d = 1 if d == 'R' else -1
        ants.append(Ant(p, d, i))

    ps = []
    c = defaultdict(int)
    for ant in ants:
        p = ant.pos + t * ant.d
        c[p] += 1
        ps.append((p, ant.d))

    ps.sort()
    ants.sort(key=lambda x: x.pos)
    # print(ps)

    res = ['' for i in xrange(n)]
    for i in xrange(n):
        idx = ants[i].idx
        p, d = ps[i]
        if p < 0 or p > l:
            res[idx] = 'Fell off'
        else:
            if c.get(p, 0) > 1:
                d = 'Turning'
            else:
                d = {-1: 'L', 1: 'R'}[d]
            res[idx] = '%d %s' % (p, d)

    for line in res:
        print(line)
    print()


'''
^^^^TEST^^^
2
10 1 4
1 R
5 R
3 L
10 R
10 2 3
4 R
5 L
8 R
-------
Case #1:
2 Turning
6 R
2 Turning
Fell off

Case #2:
3 L
6 R
10 R
$$$TEST$$$$

^^^^TEST^^^
2
3 2 2
1 R
2 L
2 2 2
1 R
2 L
------
Case #1:
0 L
3 R

Case #2:
0 L
Fell off
$$$$TEST$$$

^^^TEST^^^^
1
10 10 10
5 R
9 R
8 L
0 R
6 L
2 L
4 L
7 L
1 R
10 R
------------
Case #1:
Fell off
Fell off
Fell off
Fell off
10 R
Fell off
Fell off
Fell off
Fell off
Fell off
$$$TEST$$$

'''
