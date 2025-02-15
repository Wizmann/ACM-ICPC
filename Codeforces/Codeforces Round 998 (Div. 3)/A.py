from collections import defaultdict

T = int(raw_input())

for case_ in xrange(T):
    a1, a2, a4, a5 = map(int, raw_input().split())
    
    d = defaultdict(int)

    d[a1 + a2] += 1
    d[a4 - a2] += 1
    d[a5 - a4] += 1

    print max(d.values())

'''
^^^^TEST^^^^^
6
1 1 3 5
1 3 2 1
8 10 28 100
100 1 100 1
1 100 1 100
100 100 100 100
------------
3
2
2
1
1
2
$$$$$$$TEST$$$$
'''


