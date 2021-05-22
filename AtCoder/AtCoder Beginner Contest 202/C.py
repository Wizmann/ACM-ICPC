#coding=utf-8
from collections import defaultdict

N = int(raw_input())

A = map(int, raw_input().split())
B = map(int, raw_input().split())
C = map(int, raw_input().split())

da = defaultdict(list)
db = defaultdict(list)
dc = defaultdict(int)

for i, num in enumerate(A):
    da[num].append(i)

for i, num in enumerate(B):
    db[num].append(i)

for i, num in enumerate(C):
    dc[num - 1] += 1

res = 0
for key, values in da.items():
    if key not in db:
        continue
    u = len(values)
    v = 0
    for value2 in db[key]:
        v += dc.get(value2, 0)
    res += u * v

print res

'''
^^^TEST^^^
3
1 2 2
3 1 2
2 3 2
-----
4
$$$TEST$$$

^^^TEST^^^
4
1 1 1 1
1 1 1 1
1 2 3 4
------
16
$$$TEST$$$

^^^^TEST^^^
3
2 3 3
1 3 3
1 1 1
------
0
$$$TEST$$$


'''

