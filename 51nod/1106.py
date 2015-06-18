import math

def is_prime(n):
    if n in [1, 2]:
        return True
    for i in xrange(3, int(math.sqrt(n) + 1)):
        if n % i == 0:
            return False
    return True

T = int(raw_input())

for i in xrange(T):
    n = int(raw_input())
    print 'Yes' if is_prime(n) else 'No'
