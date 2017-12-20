def solve(a, n, p):
    u = a
    for i in xrange(2, n + 1):
        u = pow(u, i, p)
    return u % p

assert solve(2, 1, 2) == 0
assert solve(3, 3, 2) == 1

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        (a, n, p) = map(int, raw_input().split())
        print 'Case #%d: %d' % (case_ + 1, solve(a, n, p))
