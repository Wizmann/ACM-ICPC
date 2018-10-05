#coding=utf-8

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

def C(a, b):
    if a > b:
        return 0
    res = 1
    for i in xrange(a):
        res *= (b - i)
        res /= i + 1
    return res

def solve(k, s):
    res = 0
    for i in xrange(1, 1 << len(primes)):
        ps = [num for j, num in enumerate(primes) if (1 << j) & i]
        p = len(ps)
        r = reduce(lambda x, y: x * y, ps, 1)

        if p % 2 == 0:
            res -= C(k, s / r)
        else:
            res += C(k, s / r)
    return min(10000, res)

if __name__ == '__main__':
    (k, s) = map(int, raw_input().split())
    print solve(k, s)
