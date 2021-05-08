
n = int(raw_input())
ns = map(int, raw_input().split())

d = {}

res = 0
for num in ns:
    u = num % 100
    v = (num / 100) % 2

    if (u, v) in d:
        res += d[(u, v)]
    d[(u, v)] = d.get((u, v), 0) + 1

print res

'''
^^^TEST^^^
6
123 223 123 523 200 2000
----
4
$$$TEST$$$

^^^^TEST^^^
5
1 2 3 4 5
----
0
$$$TEST$$$

^^^TEST^^^
8
199 100 200 400 300 500 600 200
---
9
$$$TEST$$$

'''
