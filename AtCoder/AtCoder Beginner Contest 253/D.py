def brute_force(n, a, b):
    tot = 0
    for i in xrange(1, n + 1):
        if i % a == 0 or i % b == 0:
            continue
        tot += i
    return tot

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(a, b):
    g = gcd(a, b)
    return a / g * b

def solve(n, a, b):
    tot = (1 + n) * n / 2

    na = n / a
    tot -= (1 + na) * na / 2 * a

    nb = n / b
    tot -= (1 + nb) * nb / 2 * b

    ab = lcm(a, b)
    nab = n / ab
    tot += (1 + nab) * nab / 2 * ab

    return tot

def test(n, a, b):
    # print brute_force(n, a, b), solve(n, a, b)
    assert brute_force(n, a, b) == solve(n, a, b)

'''
import random
for i in xrange(1000):
    a, b, c = [random.randint(1, 1000) for i in xrange(3)]
    # print a, b, c
    test(a, b, c)

test(8, 3, 3)
test(100000, 1, 2)
test(99, 100, 200)
test(1, 1, 100)
test(1, 1, 1)
test(2, 2, 1)
test(82, 66, 2)

print 'ok'
'''



(n, a, b) = map(int, raw_input().split())
print solve(n, a, b)

'''
^^^^^TEST^^^
10 3 5
-------
22
$$$$TEST$$$

^^^^^TEST^^^
1000000000 314 159
-------
495273003954006262
$$$$TEST$$$
'''

