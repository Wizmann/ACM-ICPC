from math import sqrt

def f(v, a, b):
    return v * v + a * v + b
    
def isPrime(v):
    if v <= 1: 
        return False
    for i in xrange(2, int(sqrt(v) + 1)):
        if v != i and v % i == 0:
            return False
    return True


maxv = 0
ans = None

for a in xrange(-999, 1000):
    for b in xrange(-999, 1000):
        v = 0
        #print a, b
        while True:
            u = f(v, a, b)
            if not isPrime(u):
                break
            v += 1
        if v > maxv:
            maxv = v
            ans = (a, b)

print ans[0] * ans[1]
