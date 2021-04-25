#coding=utf-8

n = int(raw_input())
s = list(raw_input())
q = int(raw_input())

rev = 0

def actual_pos(x):
    if rev == 0:
        return x
    if x < n:
        return x + n
    else:
        return x - n


for case_ in xrange(q):
    t, a, b = map(int, raw_input().split())
    a -= 1
    b -= 1
    if t == 1:
        a = actual_pos(a)
        b = actual_pos(b)
        s[a], s[b] = s[b], s[a]
    else:
        rev ^= 1

if rev == 1:
    s = s[n:] + s[:n]

print ''.join(s)

'''
^^^TEST^^^
2
FLIP
2
2 0 0
1 1 4
----
LPFI
$$$TEST$$$

^^^TEST^^^
2
FLIP
6
1 1 3
2 0 0
1 1 2
1 2 3
2 0 0
1 1 4
----
ILPF
$$$TEST$$$
'''


