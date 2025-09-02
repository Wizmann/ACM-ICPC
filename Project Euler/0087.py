# coding: utf-8
import math

LIMIT = 50000000

# ----------- 筛质数 -----------
def sieve(n):
    is_prime = [True] * (n+1)
    is_prime[0] = is_prime[1] = False
    for i in xrange(2, int(math.sqrt(n)) + 1):
        if is_prime[i]:
            for j in xrange(i*i, n+1, i):
                is_prime[j] = False
    return [i for i, v in enumerate(is_prime) if v]

# ----------- 构造候选 A, B, C -----------
primes_x = sieve(7072)   # x 上限
primes_y = sieve(369)    # y 上限
primes_z = sieve(85)     # z 上限

A_list = [p**2 for p in primes_x if p**2 < LIMIT]
B_list = [p**3 for p in primes_y if p**3 < LIMIT]
C_list = [p**4 for p in primes_z if p**4 < LIMIT]

# ----------- 枚举计数 -----------
count = 0
st = set()
for a in A_list:
    for b in B_list:
        if a + b >= LIMIT:
            continue
        for c in C_list:
            if a + b + c < LIMIT:
                count += 1
                st.add(a + b + c)

print len(st)
