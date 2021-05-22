#coding=utf-8

factorials = [1]
for i in xrange(1, 64):
    factorials.append(factorials[-1] * i)

def C(a, b):
    return (factorials[b] / factorials[b - a]) / factorials[a]


a, b, k = map(int, raw_input().split())
rem = k
n = a + b
res = []
for i in xrange(n):
    base = C(a - 1, a + b - 1)

    assert(rem >= 0)

    if rem > base:
        rem -= base
        res.append('b')
        b -= 1
    else:
        if a:
            res.append('a')
            a -= 1
        else:
            res.append('b')
            b -= 1

print ''.join(res)


'''

^^^TEST^^^^
2 2 4
----
baab
$$$TEST$$$


^^^TEST^^^
30 30 118264581564861424
------
bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
$$$TEST$$$

'''





