def _is_prime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

primes = set(filter(_is_prime, range(2, 1111)))

def solve(n):
    ans = 0

    for i in xrange(2, n + 1):
        if i not in primes:
            continue
        u = i
        while u <= n:
            ans += 1
            u *= i

    return ans


if __name__ == '__main__':
    n = int(raw_input())
    print solve(n)

