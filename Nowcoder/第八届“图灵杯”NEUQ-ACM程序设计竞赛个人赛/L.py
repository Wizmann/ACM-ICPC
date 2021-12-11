n, k = map(int, raw_input().split())

ns = map(int, raw_input().split())
ns.sort()

def check(m):
    tot = 0
    for i in xrange(n - 1):
        dis = ns[i + 1] - ns[i]
        u = dis / m
        v = dis % m
        if v == 0:
            tot += u - 1
        else:
            tot += u
    return tot

l, r = 0, ns[-1]
while l <= r:
    m = (l + r) / 2
    if check(m) <= k:
        r = m - 1
    else:
        l = m + 1

print l

'''
^^^TEST^^^
2 2
4 106
-----
34
$$$TEST$$$
'''
