
def solve1(n):
    # n = k ^ a
    res = []
    for i in xrange(1, 100):
        u = int(pow(n, 1.0 / i) + 0.1)
        if u ** i == n:
            res.append(u)
    return set(res)

def solve2(n):
    # n = a * k + 1
    m = n - 1

    i = 1
    res = set()
    while i * i <= m:
        if m % i == 0:
            res.add(i)
            res.add(m / i)
        i += 1
    return res ^ set([1])

def solve3(n):
    i = 2
    res = set()
    while i * i <= n:
        if n % i == 0:
            m = n / i
            while m and m % i == 0:
                m /= i
            if m % i == 1:
                res.add(i)
        i += 1
    return res

def brute_force(n):
    res = []
    for i in xrange(2, n + 1):
        m = n
        while m % i == 0:
            m /= i
        m %= i
        if m == 1:
            res.append(i)
    # print res
    return len(res)

def solve(n):
    s1 = solve1(n)
    s2 = solve2(n)
    s3 = solve3(n)
    # print sorted(s1 | s2 | s3)
    return len(s1 | s2 | s3)

assert solve(6) == 3
assert solve(3141) == 13
assert solve(314159265358) == 9

assert solve(10 ** 12)

import random
for i in xrange(2, 100):
    assert brute_force(i) == solve(i)

n = int(raw_input())
print solve(n)
