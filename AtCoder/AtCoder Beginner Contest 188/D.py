from collections import defaultdict

n, prime = map(int, raw_input().split())

d = defaultdict(int)

for i in xrange(n):
    (a, b, c) = map(int, raw_input().split())
    d[a] += c
    d[b + 1] -= c

res = 0
pre = 0
cur = 0
for (k, v) in sorted(d.items()):
    res += (k - pre) * min(cur, prime)
    cur += v
    pre = k
    # print k, v, res
print res


'''
^^^TEST^^^
2 6
1 2 4
2 2 4
----
10
$$$TEST$$$

^^^TEST^^^
5 1000000000
583563238 820642330 44577
136809000 653199778 90962
54601291 785892285 50554
5797762 453599267 65697
468677897 916692569 87409
-----
163089627821228
$$$TEST$$$

^^^TEST^^^
5 100000
583563238 820642330 44577
136809000 653199778 90962
54601291 785892285 50554
5797762 453599267 65697
468677897 916692569 87409
----
88206004785464
$$$TEST$$$

'''



