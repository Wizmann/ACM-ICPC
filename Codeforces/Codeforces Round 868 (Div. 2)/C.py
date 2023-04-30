#coding=utf-8

from collections import defaultdict

primes = [2, 3, 5, 7]

for i in xrange(11, 12345, 2):
    for prime in primes:
        if i % prime == 0:
            break
    else:
        primes.append(i)

def solve(ns):
    d = defaultdict(int)
    for num in ns:
        for prime in primes:
            if prime > num:
                break
            while num % prime == 0:
                d[prime] += 1
                num /= prime
        if num > 1:
            d[num] += 1

    res = 0
    for key, value in d.items():
        res += value / 2
        d[key] = value % 2

    rem = sum(d.values())
    res += rem / 3

    return res

T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())

    print solve(ns)

'''
^^^^^TEST^^^^
8
2
3 6
3
3 4 5
2
2 3
3
3 10 14
2
25 30
1
1080
9
3 3 3 5 5 5 7 7 7
20
12 15 2 2 2 2 2 3 3 3 17 21 21 21 30 6 6 33 31 39
-------------
1
1
0
2
2
3
4
15
$$$$$TEST$$$$

^^^TEST^^^
1
3
3316414 6147103 7049078
------------------
3
$$$TEST$$$
'''

