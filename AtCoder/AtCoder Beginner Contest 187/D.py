from collections import defaultdict

n = int(raw_input())

ns = [map(int, raw_input().split()) for i in xrange(n)]

ns.sort(key=lambda (a, b): 2 * a + b, reverse=True)

tot, totA = 0, 0
for (a, b) in ns:
    tot += a + b
    totA += a

totB = 0
for i in xrange(n):
    (a, b) = ns[i]
    totB += a + b
    totA -= a
    if totB > totA:
        print i + 1
        break

'''
^^^TEST^^^
4
2 1
2 2
5 1
1 3
---
1
$$$TEST$$$

^^^TEST^^^
5
2 1
2 1
2 1
2 1
2 1
----
3
$$$TEST$$$

^^^TEST^^^
1
273 691
---
1
$$$TEST$$$
'''
