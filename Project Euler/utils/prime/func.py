from primes1m import primes

MAXI = max(primes) ** 2

def is_prime(x):
    assert x <= MAXI
    for prime in primes:
        if prime * prime > x:
            break
        if x % prime == 0:
            return False
    return True


