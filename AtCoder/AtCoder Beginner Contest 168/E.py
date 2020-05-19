from collections import defaultdict

MOD = (10 ** 9) + 7
assert MOD == 1000000007

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

n = int(raw_input())

ns = []
d = defaultdict(int)
zero = 0

for i in xrange(n):
    a, b = map(int, raw_input().split())
    ns.append((a, b))
    if a and b:
        s = 1 if a * b >= 0 else -1
        g = gcd(abs(a), abs(b))
        m1 = (s * abs(a) / g, abs(b) / g)
        m2 = (-s * abs(b) / g, abs(a) / g)
    elif a == 0 and b == 0:
        zero += 1
        continue
    elif a == 0:
        m1 = (1, 0)
        m2 = (0, 1)
    elif b == 0:
        m1 = (0, 1)
        m2 = (1, 0)

    d[m1] += 1
    d[m2] += 0

'''
res = 0
for i in xrange(1 << n):
    fs = []
    flag = True
    for j in xrange(n):
        if i & (1 << j):
            fs.append(ns[j])
    for i, f1 in enumerate(fs):
        for f2 in fs[i + 1:]:
            (a1, b1) = f1
            (a2, b2) = f2
            if a1 * a2 + b1 * b2 == 0:
                flag = False
                break
        if not flag:
            break
    if flag:
        res += 1
print res - 1
'''

pre = 1
for k in d.keys():
    if k[0] <= 0:
        assert (k[1], -k[0]) in d
        continue
    else:
        k1 = k
        k2 = (-k[1], k[0])

        tot = pow(2, d[k1], MOD) + pow(2, d[k2], MOD) - 1
        pre = pre * tot % MOD
print (pre - 1 + zero + MOD) % MOD
