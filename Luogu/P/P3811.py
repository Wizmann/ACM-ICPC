#coding=utf-8

def exgcd(a, b):
    if b == 0:
       return (a, 1, 0)
    (r, x, y) = exgcd(b, a % b)
    t = y
    y = x - (a / b) * y
    x = t
    return (r, x, y)


(n, p) = map(int, raw_input().split())
'''
for i in xrange(1, n + 1):
    _, t, _ = exgcd(i, p)
    assert (i * t) % p == 1
    print (p + t % p) % p
'''


inv = [0 for i in xrange(n + 1)]
inv[1] = 1;
for i in xrange(2, n + 1):
    inv[i] = (p - p / i) * inv[p % i] % p
for i in xrange(1, n + 1):
    print inv[i]


'''
^^^TEST^^^
10 13
----
1
7
9
10
8
11
2
5
3
4
$$$TEST$$$
'''
