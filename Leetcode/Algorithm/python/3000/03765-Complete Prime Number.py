def primes_under(limit):
    if limit <= 2:
        return []

    # bytearray in Py2 works well as a compact boolean array
    is_prime = bytearray([1]) * limit
    is_prime[0] = 0
    is_prime[1] = 0

    p = 2
    while p * p < limit:
        if is_prime[p]:
            start = p * p
            step = p
            is_prime[start:limit:step] = bytearray([0]) * ((limit - 1 - start) // step + 1)
        p += 1

    return [i for i in xrange(limit) if is_prime[i]]

primes = primes_under(51234)

def is_prime(num):
    if num in [0, 1]:
        return False
    for prime in primes:
        if prime * prime > num:
            return True
        if num % prime == 0:
            return False
    return True

class Solution(object):
    def completePrime(self, num):
        num = str(num)
        n = len(num)
        for i in xrange(n):
            pre = int(num[:i + 1])
            if not is_prime(pre):
                return False
            suf = int(num[i:])
            if not is_prime(suf):
                return False
        return True
