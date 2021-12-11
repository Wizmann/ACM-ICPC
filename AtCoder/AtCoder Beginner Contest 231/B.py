from collections import defaultdict

n = int(raw_input())

d = defaultdict(int)

for i in xrange(n):
    s = raw_input().strip()
    d[s] += 1

d = d.items()
d.sort(key=lambda p: p[1], reverse=True)
print d[0][0]


'''
^^^TEST^^^
5
snuke
snuke
takahashi
takahashi
takahashi
-------
takahashi
$$$TEST$$$

^^^TEST^^^
1
a
-------
a
$$$TEST$$$
'''

