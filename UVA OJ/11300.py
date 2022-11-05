#python3

'''LONG LIVE PYTHON2'''
raw_input = input
xrange = range
__map = map
map = lambda func, ns: list(__map(func, ns))
'''LONG LIVE PYTHON2'''

while True:
    try:
        n = int(input())
    except:
        break

    ns = map(int, [input() for i in xrange(n)])

    m = sum(ns) // n

    ms = [0]
    v = 0
    for i in xrange(1, n):
        v += ns[i]
        ms.append(i * m - v)
    ms.sort()
    pivot = ms[n // 2]

    res = abs(pivot)
    v = 0
    for i in xrange(1, n):
        v += ns[i]
        res += abs(v - i * m + pivot)
    print(res)

'''
^^^^^TEST^^^^^
3
100
100
100
4
1
2
5
4
--------
0
4
$$$TEST$$$$$
^^^^^^^^TEST^^^
5
1
2
3
4
5
---------
4
$$$TEST$$$

^^^^^^^^TEST^^^
5
6
37
88
67
100
-------
93
$$$TEST$$$

^^^^^^^^TEST^^^
4
3
5
4
3
-------
4
$$$TEST$$$
'''



