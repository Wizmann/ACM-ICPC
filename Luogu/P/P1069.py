#python3
#coding=utf-8
from collections import defaultdict

INF = 10 ** 100

import sys
if sys.version_info[0] == 3:
    raw_input = input
    xrange = range
    map_ = map
    def map(*args, **kwargs):
        return list(map_(*args, **kwargs))

SIZE = 51234

sieve = [0 for i in xrange(SIZE)]

for i in xrange(2, SIZE):
    if sieve[i] == 1:
        continue
    j = 2
    while i * j < SIZE:
        sieve[i * j] = 1
        j += 1

primes = []
for i in xrange(2, SIZE):
    if sieve[i] == 0:
        primes.append(i)

n = int(raw_input())

m1, m2 = map(int, raw_input().split())

d = defaultdict(int)
for prime in primes:
    while m1 % prime == 0:
        m1 /= prime
        d[prime] += 1
    if d[prime]:
        d[prime] *= m2
    

mini = INF
for s in map(int, raw_input().split()):
    # print(s)
    ans = 0
    for key, value in d.items():
        cnt = 0
        if value == 0:
            continue
        while s % key == 0:
            cnt += 1
            s //= key
        # print(key, value, cnt)
        if cnt == 0:
            ans = INF
            break
        ans = max(ans, (value + cnt - 1) // cnt)
    mini = min(mini, ans)
if mini >= INF:
    mini = -1
print(mini)

'''
^^^^^TEST^^^^
1 
2 1 
3
-----------
-1
$$$$TEST$$$

^^^^^TEST^^^^
2
24 1
30 12
-----------
2
$$$$TEST$$$
'''
