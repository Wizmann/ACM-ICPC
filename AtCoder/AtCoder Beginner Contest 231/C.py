n, q = map(int, raw_input().split())

ns = map(int, raw_input().split())
ns.sort()

for i in xrange(q):
    x = int(raw_input())
    l, r = 0, n - 1
    while l <= r:
        m = (l + r) / 2
        if ns[m] >= x:
            r = m - 1
        else:
            l = m + 1
    print n - l


'''
^^^TEST^^^
3 1
100 160 130
120
------
2
$$$TEST$$$


^^^TEST^^^
5 5
804289384 846930887 681692778 714636916 957747794
424238336
719885387
649760493
596516650
189641422
------
5
3
5
5
5
$$$TEST$$$

^^^TEST^^^
5 5
1 2 3 4 5
6
5
4
3
2
-------
0
1
2
3
4
$$$TEST$$$

'''
