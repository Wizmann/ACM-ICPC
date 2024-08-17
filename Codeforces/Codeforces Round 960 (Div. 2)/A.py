from collections import Counter

T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())

    c = sorted(Counter(ns).items())
    cnt = 0

    for (k, v) in c[::-1]:
        cnt += v
        if cnt % 2:
            break

    if cnt % 2:
        print 'YES'
    else:
        print 'NO'

'''
^^^^^^TEST^^^^
5
2
2 1
2
1 1
3
3 3 3
4
3 3 4 4
4
1 2 2 2
-------------
YES
NO
YES
NO
YES
$$$$TEST$$$$
'''


