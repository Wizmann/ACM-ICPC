def is_prime(x):
    if x < 2:
        return False
    p = 2
    while p * p <= x:
        if x % p == 0:
            return False
        p += 1
    return True

res = [2, 3, 5, 7]

for i in xrange(1, 12345):
    u = int(str(i) + str(i)[::-1])
    if is_prime(u):
        res.append(u)

for i in xrange(1, 1234):
    for j in xrange(10):
        u = int(str(i) + str(j) + str(i)[::-1])
        if is_prime(u):
            res.append(u)

primes = sorted(set(res))


class Solution(object):
    def primePalindrome(self, N):
        l, r = 0, len(primes) - 1
        while l <= r:
            m = (l + r) >> 1
            if primes[m] < N:
                l = m + 1
            else:
                r = m - 1
        return primes[l]
        
