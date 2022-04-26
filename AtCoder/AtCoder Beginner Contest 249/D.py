#coding=utf-8
from collections import defaultdict

d = defaultdict(int)

n = int(raw_input())
ns = map(int, raw_input().split())

for num in ns:
    d[num] += 1
    
res = 0
for num in ns:
    if num == 1:
        res += d[1] ** 2
        continue

    for i in xrange(1, num):
        if i * i > num:
            break
        if num % i != 0:
            continue
        a, b = i, num / i
        if a == b:
            res += d[a] ** 2
        else:
            res += d[a] * d[b] * 2
print res





'''
^^^^TEST^^^
3
6 2 3
------
2
$$$TEST$$$

^^^^TEST^^^
1
2
------
0
$$$TEST$$$

^^^TEST^^^^
10
1 3 2 4 6 8 2 2 3 7
-----
62
$$$TEST$$$
'''

