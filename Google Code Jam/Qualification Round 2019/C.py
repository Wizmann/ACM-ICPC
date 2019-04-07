import string

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

T = int(raw_input())

for case_ in xrange(T):
    (m, n) = map(int, raw_input().split())
    ns = map(int, raw_input().split())
    ps = []
    for i in xrange(1, n):
        u = gcd(ns[i - 1], ns[i])
        if i == 1:
            ps.append(ns[0] / u)
        ps.append(u)
        if i == n - 1:
            ps.append(ns[-1] / u)

    assert len(set(ps)) == 26

    d = dict(zip(sorted(set(ps)), string.uppercase))
    print 'Case #%d: %s' % (case_ + 1, ''.join(map(lambda c: d[c], ps)))
