primes = [2, 3, 5]

for i in xrange(7, 10 ** 6):
    for prime in primes:
        if prime * prime > i:
            primes.append(i)
            break
        elif i % prime == 0:
            break

from collections import defaultdict

def sum_for_list(lst):
    d = defaultdict(list)
    for item in lst:
        for prime in primes:
            if prime > abs(item):
                break
            elif item % prime == 0:
                d[prime].append(item)
    res = []
    for key, values in d.items():
        res.append([key, sum(values)])
    return sorted(res)
