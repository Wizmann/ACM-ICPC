from itertools import permutations

def fac(x):
    return reduce(lambda x, y: x * y, range(1, x + 1), 1)

def solve(s, k):
    s = list(s)
    n = len(s)
    f = fac(n)

    k %= f
    if k == 0:
        return ''.join(s)

    f = fac(n - 1)
    a, b = k / f, k % f

    c = s[a]
    s[a] = s[0]
    r = sorted(s[1:])

    return c + solve(r, b)

assert solve('abc', 0) == 'abc'
assert solve('abc', 1) == 'acb'

for i, s in enumerate(permutations('abcd')):
    s = ''.join(s)
    assert s == solve('abcd', i)

s = 'abcdefghijklm'

T = int(raw_input())

for case_ in xrange(T):
    k = int(raw_input())
    print solve(s, k - 1)
