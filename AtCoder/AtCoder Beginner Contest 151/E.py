N = 123456
MOD = (10 ** 9) + 7

fs = [1 for i in xrange(N)]
for i in xrange(1, N):
    fs[i] = fs[i - 1] * i % MOD

n, k = map(int, raw_input().split())
ns = map(int, raw_input().split())
ns.sort()

def fermat(u):
    return pow(u, MOD - 2, MOD)

def C(a, b):
    if b > a:
        return 0
    if b == 0:
        return 0
    assert a - b >= 0
    res = fs[a] * fermat(fs[b]) % MOD * fermat(fs[a - b]) % MOD
    return res % MOD

assert C(5, 3) == 10

res = 0
for i in xrange(n):
    res += C(i, k - 1) * ns[i] % MOD
    res %= MOD
    res -= C(n - i - 1, k - 1) * ns[i] % MOD
    res = ((res % MOD) + MOD) % MOD

print res
