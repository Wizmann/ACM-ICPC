#coding=utf-8

T = int(raw_input())

for case_ in xrange(T):
    n, k = map(int, raw_input().split())
    extra = n - k + 1
    res = range(1, k - extra + 1) + \
            sorted(range(k - extra + 1, k + 1), reverse=True)
    print ' '.join(map(str, res)).strip()

'''
^^^TEST^^^
4
1 1
2 2
3 2
4 3
-----
1
1 2
2 1
1 3 2
$$$TEST$$$
'''
