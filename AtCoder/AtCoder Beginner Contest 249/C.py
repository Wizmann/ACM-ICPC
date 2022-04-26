from collections import Counter
import string

n, k = map(int, raw_input().split())

ss = []
for i in xrange(n):
    ss.append(raw_input())

res = 0
for i in xrange(1 << n):
    buf = ''
    for j in xrange(n):
        if i & (1 << j):
            buf += ss[j]

    d = Counter(buf)
    cnt = 0
    for c in string.ascii_lowercase:
        if d[c] == k:
            cnt += 1
    res = max(res, cnt)
print res

'''
^^^^^TEST^^^
4 2
abi
aef
bc
acg
------
3
$$$TEST$$$$

^^^TEST^^^
5 2
abpqxyz
az
pq
bc
cy
-----
7
$$$TEST$$$

^^^^^TEST^^^^
2 2
a
b
------
0
$$$TEST$$$

'''

