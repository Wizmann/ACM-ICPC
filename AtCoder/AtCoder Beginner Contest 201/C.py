#coding=utf-8

def C(m, n):
    res = 1
    for i in xrange(m):
        res = res * (n - i)
        res /= i + 1
    return res

def A(m, n):
    res = 1
    for i in xrange(m):
        res = res * (n - i)
    return res

s = raw_input()
a, b = s.count('o'), s.count('?')

res = 0

for i in xrange(4 - a + 1):
    m = C(i, b)
    c = a + i
    cur = 0
    if c == 0:
        continue
    elif c == 1:
        cur = 1
    elif c == 2:
        cur = ((1 << 4) - 2)
    elif c == 3:
        cur = A(4, 4) / A(2, 2) * 3
    elif c == 4:
        cur = A(4, 4)
    else:
        assert False
    # print i, c, m, cur
    res += m * cur
print res

'''
^^^TEST^^^
ooo???xxxx
-----
108
$$$TEST$$$

^^^TEST^^^
o?oo?oxoxo
-----
0
$$$TEST$$$

^^^TEST^^^
xxxxx?xxxo
-----
15
$$$TEST$$$
'''
