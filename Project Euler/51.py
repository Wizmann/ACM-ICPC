import sys
from utils.prime.primes1m import primes

primes_set = set(primes)
visited = set()

for prime in primes:
    sp = str(prime)
    l = len(sp)
    for i in xrange(1, 1 << l):
        s = set()
        for j in xrange(l):
            if i & (1 << j):
                s.add(sp[j])
        if len(s) != 1:
            continue
        cur = int(list(s)[0])
        cnt = 0
        pp = []
        for j in xrange(cur, 10):
            dup = map(int, list(sp))
            for k in xrange(l):
                if i & (1 << k):
                    dup[k] = j
            dup_i = int(''.join(map(str, dup)))
            if dup_i in primes_set:
                cnt += 1
                pp.append(dup_i)
        if cnt == 8:
            print '>>', prime
            print pp
            sys.exit(0)
'''
>> 121313
[121313, 222323, 323333, 424343, 525353, 626363, 828383, 929393]
'''
