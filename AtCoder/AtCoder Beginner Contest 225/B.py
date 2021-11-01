from collections import defaultdict

n = int(raw_input())

d = defaultdict(int)

for i in xrange(n - 1):
    (a, b) = map(int, raw_input().split())
    d[a] += 1
    d[b] += 1

vs = sorted(d.values())

if vs[-1] == n - 1 and set(vs[:-1]) == set([1]):
    print 'Yes'
else:
    print 'No'


'''

^^^TEST^^^
5
1 4
2 4
3 4
4 5
-------
Yes
$$$TEST$$$

^^^TEST^^^
4
2 4
1 4
2 3
-------
No
$$$TEST$$$

^^^TEST^^^
10
9 10
3 10
4 10
8 10
1 10
2 10
7 10
6 10
5 10
-------
Yes
$$$TEST$$$

'''
