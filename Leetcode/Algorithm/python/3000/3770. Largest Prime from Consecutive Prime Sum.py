N = 512345
sieve = [True for i in xrange(N)]

for i in xrange(2, N):
    j = 2
    while i * j < N:
        sieve[i * j] = False
        j += 1

primes = []
for i in xrange(2, N):
    if sieve[i]:
        primes.append(i)
st = set(primes)

candidates = []
acc = 0
for prime in primes:
    acc += prime
    if acc in st:
        candidates.append(acc)
    if acc > N:
        break

class Solution(object):
    def largestPrime(self, n):
        l, r = 0, len(candidates) - 1
        while l <= r:
            m = (l + r) / 2
            if candidates[m] > n:
                r = m - 1
            else:
                l = m + 1
        if r < 0 or r >= len(candidates):
            return 0
        return candidates[r]
        
