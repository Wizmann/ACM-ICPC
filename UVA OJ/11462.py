#python3
from collections import defaultdict, Counter

while True:
    n = int(input())
    if not n:
        break
    ns = Counter(map(int, input().split()))

    res = []
    for i in range(1, 101):
        for j in range(ns[i]):
            res.append(i)
    print(' '.join(map(str, res)))

'''
^^^^^TEST^^^^
5
3 4 2 1 5
5
2 3 2 3 1
0
------------
1 2 3 4 5
1 2 2 3 3
$$$TEST$$$
'''
