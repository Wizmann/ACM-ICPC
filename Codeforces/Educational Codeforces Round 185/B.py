T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = filter(lambda x: x, map(int, raw_input().split()))
    ns.sort()

    if ns[-1] == n:
        print len(ns)
    else:
        delta = sum(ns) - len(ns) - (n - 1)
        if delta >= 0:
            print len(ns)
        else:
            print len(ns) + delta

'''
^^^^TEST^^^^
3
5
0 5 1 0 1
3
3 2 1
5
1 1 1 1 1
----------
3
3
1
$$$$$$$TEST$$$$$

^^^^TEST^^^^
4
5
3 1 2 0 0
3
0 2 3
3
0 3 0
3
0 2 2
----------
2
2
1
2
$$$$$$$TEST$$$$$
'''



