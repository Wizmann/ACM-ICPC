MOD = int(1e9 + 7)
BITS = 32

fact = [1]
ifact = [1]

def init_comb(n):
    global fact, ifact
    fact = [1 for i in xrange(n + 1)]
    ifact = [1 for i in xrange(n + 1)]
    for i in xrange(1, n + 1):
        fact[i] = fact[i - 1] * i % MOD
    ifact[n] = pow(fact[n], MOD - 2, MOD)
    for i in xrange(n, 0, -1):
        ifact[i - 1] = ifact[i] * i % MOD

def C(a, b):
    # e.g. C(5, 3) = 10
    if b < 0 or b > a:
        return 0
    return fact[a] * ifact[b] % MOD * ifact[a - b] % MOD

def solve(n, b):
    bits = [0 for i in xrange(BITS)]
    for i in xrange(n - 1, -1, -1):
        for j in xrange(BITS):
            b[i] -= C(bits[j], i + 1) * (1 << j)
        b[i] = ((b[i] % MOD) + MOD) % MOD
        for j in xrange(BITS):
            if b[i] & (1 << j):
                bits[j] += i + 1
    res = []
    for i in xrange(n):
        cur = 0
        for j in xrange(BITS):
            if bits[j]:
                cur += (1 << j)
                bits[j] -= 1
        res.append(cur)
    return res

T = int(raw_input())
cases = []
maxn = 0

for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())
    cases.append((n, ns))
    maxn = max(maxn, n)

init_comb(maxn)

for n, ns in cases:
    res = solve(n, ns)
    print ' '.join(map(str, res))

'''
^^^^^TEST^^^^
3
3
0 0 0
5
22 24 10 1 0
10
130 585 1560 2730 3276 2730 1560 585 130 13
--------------
0 0 0
5 3 6 1 7
13 13 13 13 13 13 13 13 13 13
$$$$$$$TEST$$$$
'''

