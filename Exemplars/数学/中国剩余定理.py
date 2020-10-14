'''
中国剩余定理说明：假设整数m1, m2, ... , mn其中任两数互质，则对任意的整数：a1, a2, ... , an，方程组S有解，
S = {
x % m1 == a1
x % m2 == a2
x % m3 == a3
...
}

题意：
给定A[n]和B[n]，B[n]两两互值。
求最小值k，使得对于任意i，有k % B[i] = A[i]。
'''
#coding=utf-8

def exgcd(a, b):
    if b == 0:
       return (a, 1, 0)
    (r, x, y) = exgcd(b, a % b)
    t = y
    y = x - (a / b) * y
    x = t
    return (r, x, y)

n = int(raw_input())
A = map(int, raw_input().split())
B = map(int, raw_input().split())

tot = reduce(lambda x, y: x * y, B)
res = 0

for i in xrange(n):
    a = A[i]
    b = B[i]
    rem = tot / b
    gcd, t1, t2 = exgcd(rem, b)
    assert (rem * t1) % b == 1
    res += a * t1 * rem
    res %= tot
print res 


'''
^^^TEST^^^
3
1 2 3
2 3 5
----
23
$$$TEST$$$
'''

