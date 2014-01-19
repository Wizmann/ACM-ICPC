#coding=utf-8
from math import sqrt

def isPrime(v):
    if v == 2:
        return True
    u = int(sqrt(v) + 1)
    for i in xrange(2, u + 1):
        if v % i == 0:
            return False
    return True


prime = [i for i in xrange(2, 1000000) if isPrime(i)]
print prime[10000]
