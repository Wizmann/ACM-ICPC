import sys

N = 55555
sieve = [False for i in xrange(N)]

for i in xrange(2, N):
    j = 2
    if sieve[i]:
        continue
    while i * j < N:
        sieve[i * j] = True
        j += 1
        
primes = []
for i in xrange(2, N):
    if not sieve[i]:
        primes.append(i)

def factor_count(n):
    u = 1
    for prime in primes:
        if prime * prime > n:
            break
        v = 0
        while n % prime == 0:
            v += 1
            n /= prime
        u *= v + 1
    if n != 1:
        u *= 2
        
    return u

d = {}

for i in xrange(1, N):
    l = (1 + i) * i / 2
    u = factor_count(l)
    if u in d:
        continue
    for j in xrange(u, 0, -1):
        if j not in d:
            d[j] = l
        else:
            break

            
if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        print d[n + 1]
