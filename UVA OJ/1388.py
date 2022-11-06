#python3

'''LONG LIVE PYTHON2'''
raw_input = input
xrange = range
__map = map
map = lambda func, ns: list(__map(func, ns))
__filter = filter
filter = lambda func, ns: list(__filter(func, ns))
'''LONG LIVE PYTHON2'''

while True:
    try:
        n, m = map(int, input().split())
    except:
        break

    res = 0
    for i in xrange(1, n):
        pos = int(1.0 * i * (n + m) / n + 0.5)
        delta = abs(1.0 * i * (n + m) / n - pos)
        res += delta * 10000 / (n + m)

    print('%.4f' % res)

'''
^^^^^TEST^^^^^
2 1
2 3
3 1
10 10
--------
1666.6667
1000.0
1666.6667
0.0
$$$TEST$$$$$
'''

