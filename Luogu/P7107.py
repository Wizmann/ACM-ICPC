def check(n, m, k, p, res):
    if len(res) != n:
        return False
    mark = 0
    tot = 0
    maxi = -1
    for (a, b) in res:
        if a < 0 or b < 0:
            return False
        maxi = max(maxi, a)
        mark += a
        tot += a + b
    mcnt = 0
    for (a, b) in res:
        if a == maxi:
            mcnt += 1
    if mcnt != p:
        return False
    if mark != k:
        return False
    if tot != n * m:
        return False
    return True

def solve(n, m, k, p):
    nn, mm, kk, pp = n, m, k, p
    maxi = min(m, k / p)
    tot = n * m
    res = []
    for i in xrange(p):
        res.append((maxi, m - maxi))
        k -= maxi
        tot -= m

    while k > 0 and maxi > 0:
        maxi = min(maxi - 1, k)
        while k > 0 and maxi > 0 and k >= maxi:
            res.append((maxi, m - maxi))
            k -= maxi
            tot -= m

    for i in xrange(tot / m):
        res.append((0, m))

    if check(nn, mm, kk, pp, res):
        return res
    else:
        return []

assert solve(3, 3, 5, 2)
assert not solve(3, 3, 3, 2)
assert not solve(3, 3, 5, 3)

if __name__ == '__main__':
    (n, m, k, p) = map(int, raw_input().split())
    res = solve(n, m, k, p)
    if res:
        print 'YES'
        for (a, b) in res:
            print a, b
    else:
        print 'NO'
