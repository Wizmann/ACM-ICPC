#coding=utf-8
from collections import Counter

T = int(raw_input())

for case_ in xrange(T):
    n, m = map(int, raw_input().split())
    ns = map(int, raw_input().split())

    c = Counter()
    for num in ns:
        c[num % m] += 1

    res = 0
    # print c
    for i in xrange(m / 2 + 1):
        if i == 0 or i * 2 == m:
            # print '>>', i
            if c[i]:
                res += 1
            continue

        a = i
        b = m - i
        mini = min(c[a], c[b])
        maxi = max(c[a], c[b])

        # print i, mini, maxi

        if maxi == 0:
            continue

        if c[a] == c[b]:
            res += 1
            continue

        if maxi > 0 and mini == 0:
            res += maxi
            continue

        res += (maxi - mini - 1) + 1
    print res

'''
^^^TEST^^^
8
6 4
2 2 8 6 9 4
10 8
1 1 1 5 2 4 4 8 6 7
1 1
666
2 2
2 4
6 3
2 2 8 6 9 4
6 3
1 2 1 2 1 2
5 3
1 2 1 2 1
7 3
1 2 1 2 1 1 1 
-----
3
6
1
1
3
1
1
3
$$$TEST$$$
'''
