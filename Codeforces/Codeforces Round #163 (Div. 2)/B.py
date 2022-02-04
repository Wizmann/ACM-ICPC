n, t = map(int, raw_input().split())
ns = list(raw_input())

for i in xrange(t):
    ns2 = ns[:]
    for j in xrange(n - 1):
        if ns[j] == 'B' and ns[j + 1] == 'G':
            ns2[j], ns2[j + 1] = ns2[j + 1], ns2[j]
    ns = ns2

print ''.join(ns)

'''
^^^TEST^^^
5 1
BGGBG
------
GBGGB
$$$TEST$$$

^^^TEST^^^
5 2
BGGBG
---------
GGBGB
$$$TEST$$$

^^^TEST^^^
4 1
GGGB
---------
GGGB
$$$TEST$$$
'''

