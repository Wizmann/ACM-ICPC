#python3
from collections import defaultdict

T = int(input())

for case_ in range(T):
    n = int(input())
    ns = map(int, input().split())

    tot = 0
    left = 0
    p = 0
    ms = defaultdict(int)
    res = []
    for num in ns:
        ms[num] += 1
        tot += 1
        if num <= p:
            left += 1
        while tot - left > p:
            p += 1
            left += ms[p]
        res.append(p)
    print("Case #%d: %s" % (case_ + 1, ' '.join(map(str, res))))

'''
^^^TEST^^^
2
3
5 1 2
6
1 3 3 2 2 15
-------
Case #1: 1 1 2
Case #2: 1 1 2 2 2 3
$$$TEST$$$
'''
