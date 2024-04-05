#coding=utf-8

ns = map(int, raw_input().split())
n = sum(ns)

def factorial(x):
    return reduce(lambda x, y: x * y, range(1, x + 1))

res = 1.0 * factorial(7) * reduce(lambda x, y: x * y, ns) / reduce(lambda x, y: x * y, range(n - 5, n + 1))

print '%.3f' % res

'''
^^^TEST^^^
1 1 1 1 1 1 1
---
1.000
$$$TEST$$$
'''

