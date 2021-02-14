#coding=utf-8

T = int(raw_input())
for case_ in xrange(T):
    n, m = map(int, raw_input().split())
    ns = sorted(map(int, raw_input().split()))
    if ns[-1] <= m or ns[0] + ns[1] <= m:
        print 'YES'
    else:
        print 'NO'

'''
^^^TEST^^^
3
5 3
2 3 2 5 4
3 4
2 4 4
5 4
2 1 5 3 6
----
NO
YES
YES
$$$TEST$$$
'''
