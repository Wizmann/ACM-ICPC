from math import sqrt

def is_prime(x):
    for i in xrange(2, int(sqrt(x) + 1)):
        if x % i == 0:
            return False
    return True
    
def rotate(v):
    res = []
    u = str(v)
    while True:
        u = u[1:] + u[0]
        w = int(u)
        if w == v:
            break
        res.append(w)
    return res

MILLION = 1000000

primes = filter(is_prime, range(2, MILLION))

s = set(primes)

ans = 0
for item in primes:
    flag = True
    print item
    for y in rotate(item):
        if y not in s:
            flag = False
    if flag:
        ans += 1

print ans
