#coding=utf-8

n, s, d = map(int, raw_input().split())

spells = []

for i in xrange(n):
    a, b = map(int, raw_input().split())
    spells.append((a, b))

flag = False
for (a, b) in spells:
    if a >= s or b <= d:
        continue
    flag = True

if flag:
    print 'Yes'
else:
    print 'No'



'''
^^^TEST^^^
4 9 9
5 5
15 5
5 15
15 15
-----
Yes
$$$TEST$$$

^^^TEST^^^
3 691 273
691 997
593 273
691 273
----
No
$$$TEST$$$

^^^TEST^^^
7 100 100
10 11
12 67
192 79
154 197
142 158
20 25
17 108
----
Yes
$$$TEST$$$
'''
