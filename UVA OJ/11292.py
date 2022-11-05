#python3

'''LONG LIVE PYTHON2'''
xrange = range
__map = map
map = lambda func, ns: list(__map(func, ns))
'''LONG LIVE PYTHON2'''

while True:
    n, m = map(int, input().split())
    if n + m == 0:
        break

    ns = map(int, [input() for i in xrange(n)])
    ms = map(int, [input() for i in xrange(m)])

    ns.sort()
    ms.sort()

    pn, pm = 0, 0
    kill = 0
    cost = 0
    while pn < n and pm < m:
        if ms[pm] >= ns[pn]:
            kill += 1
            cost += ms[pm]
            pm += 1
            pn += 1
        else:
            pm += 1
    if kill == n:
        print(cost)
    else:
        print('Loowater is doomed!')

'''
^^^^^TEST^^^^^
2 3
5
4
7
8
4
2 1
5
5
10
0 0
--------
11
Loowater is doomed!
$$$TEST$$$$$
'''



