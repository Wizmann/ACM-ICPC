n = int(raw_input())

SIZE = 1234567 * 2

sieve = [0 for i in xrange(SIZE)]

for i in xrange(2, SIZE):
    if sieve[i] == 1:
        continue
    j = 2
    while i * j < SIZE:
        sieve[i * j] = 1
        j += 1

primes = []

for k, v in enumerate(sieve):
    if v == 0:
        primes.append(k)
        
primes = primes[2:]

primes_set = set(primes)

pp = []

for i, prime in enumerate(primes):
    if i + 1 in primes_set:
        pp.append(prime)
        
l, r = 0, len(pp)

while l <= r:
    m = (l + r) >> 1
    if pp[m] < n:
        l = m + 1
    else:
        r = m - 1

print pp[l]
