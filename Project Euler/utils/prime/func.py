from primes1m import primes
def is_prime(x):
    for prime in primes:
        if prime * prime > x:
            break
        if x % prime == 0:
            return False
    return True


