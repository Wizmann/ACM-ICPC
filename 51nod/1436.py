import sys

d = {}
MOD = (10 ** 9) + 7

def calc(n, flag):
    if n == 1:
        return [1, 0, 0, 1][flag]
    if (n, flag) in d:
        return d[(n, flag)]
    m = n >> 1

    res = 0
    for i in xrange(4):
        for j in xrange(4):
            t0 = (i & 0x2) | (j & 0x1)
            t1 = (i & 0x1) | (j & 0x2)
            if t0 != flag or t1 == 0x3:
                continue
            res = (res + calc(m, i) * calc(n - m, j)) % MOD
    d[(n, flag)] = res
    return res


(n, k, l, m) = map(int, raw_input().split())
MOD = m

if k >= (1 << l):
    print 0
    sys.exit(0)

v0 = sum([calc(n, i) for i in xrange(4)])
v1 = pow(2, n, MOD) - v0

#print v0, v1

ans = 1
for i in xrange(l):
    if k & (1 << i):
        ans = (ans * v1) % MOD
    else:
        ans = (ans * v0) % MOD

print ans % MOD
