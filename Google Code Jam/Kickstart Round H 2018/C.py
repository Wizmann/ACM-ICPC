N = 123456 * 2
MOD = 1000000007


fac = [1, 1]
for i in xrange(2, N):
    fac.append(fac[-1] * i % MOD)

def C(a, b):
    return fac[a] * pow(fac[a - b], MOD - 2, MOD) * pow(fac[b], MOD - 2, MOD) % MOD

assert C(3, 3) == 1
assert C(3, 2) == 3
assert C(3, 1) == 3
assert C(3, 0) == 1

def solve(m, n):
    res = fac[m * 2]
    for i in xrange(1, n + 1):
        u = C(n, i)
        g = -1 if i % 2 == 1 else 1
        t = fac[m * 2 - i * 2 + i] 
        res += g * u * t * pow(2, i, MOD) % MOD
        res %= MOD
    return res % MOD

assert solve(2, 1) == 12
assert solve(2, 2) == 8
assert solve(3, 1) == 480
assert solve(3, 2) == 336
assert solve(10, 5) == 560963525


if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        print 'Case #%d:' % (case_ + 1),
        (m, n) = map(int, raw_input().split())
        print solve(m, n)
