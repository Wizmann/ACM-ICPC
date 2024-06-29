MOD = 0xdeadbeefcafebabe
PRIME = 7
LENGTH = 123456

FACTOR = [pow(PRIME, i, MOD) for i in xrange(LENGTH)]

def solve(n, k, ns):
    m = n - n % k
    h1 = 0
    h2 = 0

    for i in xrange(m):
        if (i / k) % 2 == 0:
            h1 += (1 + 1) * FACTOR[m - i - 1] % MOD
        else:
            h1 += (0 + 1) * FACTOR[m - i - 1] % MOD
        h1 %= MOD

    for i in xrange(m):
        if (i / k) % 2 == 0:
            h2 += (0 + 1) * FACTOR[m - i - 1] % MOD
        else:
            h2 += (1 + 1) * FACTOR[m - i - 1] % MOD
        h2 %= MOD

    ll, rr = 0, 0
    lcnt, rcnt = 0, m

    for i in xrange(m):
        rr += FACTOR[m - i - 1] * (ns[n - i - 1] + 1) % MOD
        rr %= MOD

    for p in xrange(n, 0, -1):
        h = (rr + ll * FACTOR[rcnt] % MOD) % MOD
        # print h, [h1, h2]
        if h in [h1, h2]:
            return p
        rr -= FACTOR[rcnt - 1] * ns[p - 1]
        rr = (rr % MOD + MOD) % MOD
        ll += FACTOR[lcnt] * ns[p - 1]
        ll %= MOD
        rcnt -= 1
        lcnt += 1
    return -1

T = int(raw_input())

for case_ in xrange(T):
    n, k = map(int, raw_input().split())
    ns = map(int, raw_input())

    res = solve(n, k, ns)
    if res != -1:
        # print ns[:res] + ns[res:][::-1]
        print res
    else:
        print -1
