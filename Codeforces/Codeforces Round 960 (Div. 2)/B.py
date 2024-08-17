T = int(raw_input())

for case_ in xrange(T):
    n, y, x = map(int, raw_input().split())
    ns = [0] * n

    l = x - 1
    r = n - y
    p = -1
    for i in xrange(l - 1, -1, -1):
        ns[i] = p
        p *= -1
    for i in xrange(x - 1, y):
        ns[i] = 1
    p = -1
    for i in xrange(y, n):
        ns[i] = p
        p *= -1
    print ' '.join(map(str, map(int, ns)))

'''
^^^^^TEST^^^^
3
2 2 1
4 4 3
6 5 1
-----------
1 1
1 -1 1 1
1 1 -1 1 1 -1
$$$$TEST$$$

^^^^TEST^^^^
1
5 2 1
------
1 1 -1 -1 -1
$$$$TEST$$$
'''


