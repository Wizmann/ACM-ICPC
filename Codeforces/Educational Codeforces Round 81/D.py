def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)
 
T = int(raw_input())
 
def phi(x):
    i = 2
    res = 1
    while i < 123456:
        cnt = 0
        while x % i == 0:
            x /= i
            cnt += 1
        if cnt:
            res *= (i ** (cnt - 1)) * (i - 1)
        if i == 2:
            i += 1
        else:
            i += 2
    if x > 1:
        res *= x - 1
    return res
 
def solve(a, b):
    g = gcd(a, b)
    a = a / g
    b = b / g
    p = phi(b)
    return p
 
def brute_force(a, b):
    g = gcd(a, b)
    cnt = 0
    for i in xrange(b):
        if gcd(a + i, b) == g:
            cnt += 1
    return cnt
 
'''
from random import randint
 
for i in xrange(10000):
    a, b = randint(1, 10 ** 3), randint(1, 10 ** 3)
    assert solve(a, b) == brute_force(a, b)
'''
 
for case_ in xrange(T):
    (a, b) = map(int, raw_input().split())
    print solve(a, b)
 
