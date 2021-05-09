def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

K, N, M = map(int, raw_input().split())
ns = map(int, raw_input().split())

g = gcd(N, M)
nn = N / g
mm = M / g

def check(res, m):
    for num in ns:
        u = num * mm
        # print u, m, nn
        v = (u - m + nn - 1) / nn
        v = max(v, 0)
        if abs(v * nn - u) > m:
            return -1
        res.append(v)
    rem = M - sum(res)
    if rem < 0:
        return rem
    # print '>1', m, res, rem
    for i, num in enumerate(ns):
        u = num * mm
        v = (u + m) / nn
        if res[i] < v:
            delta = min(rem, v - res[i])
            res[i] += delta
            rem -= delta
            if rem == 0:
                break
    # print '>2', m, res, rem
    return rem

l, r = 0, nn

while l <= r:
    res = []
    m = (l + r) / 2;
    rem = check(res, m)
    if rem == 0:
        r = m - 1
    else:
        l = m + 1

res = []
check(res, l)
assert(sum(res) == M)
print ' '.join(map(str, res))

'''
^^^TEST^^^
3 7 20
1 2 4
----
3 6 11
$$$TEST$$$  

^^^TEST^^^
3 7 20
1 2 4
----
3 6 11
$$$TEST$$$  

^^^TEST^^^
3 3 100
1 1 1
----
34 33 33
$$$TEST$$$  


^^^TEST^^^
6 10006 10
10000 3 2 1 0 0
----
10 0 0 0 0 0
$$$TEST$$$  

^^^TEST^^^
7 78314 1000
53515 10620 7271 3817 1910 956 225
----
683 136 93 49 24 12 3
$$$TEST$$$  

'''


