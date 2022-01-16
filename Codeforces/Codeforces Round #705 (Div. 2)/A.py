T = int(raw_input())

for case_ in xrange(T):
    n, k = map(int, raw_input().split())
    res = []

    res += range(k + 1, n + 1)
    res += range((k + 1) / 2, k)
    print len(res)
    print ' '.join(map(str, sorted(res)))

'''
^^^^TEST^^^
4
3 2
5 3
1 1
7 7
------
2
1 3
3
2 4 5
0

3
4 5 6
$$$TEST$$$

'''

