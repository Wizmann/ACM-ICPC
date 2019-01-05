def solve(n, m, ps):
    res = 2 ** n
    for p in ps:
        cnt = 0
        for q in ps:
            if p.startswith(q):
                cnt += 1

        if cnt > 1:
            continue
        u = 2 ** (n - len(p))
        res -= u
    return res

assert(solve(4, 2, ['R', 'B']) == 0)
assert(solve(4, 3, ['R', 'B', 'RBRB']) == 0)
assert(solve(3, 2, ['BBB', 'RB']) == 5)
assert(solve(5, 1, ['R']) == 16)

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        print 'Case #%d: ' % (case_ + 1),
        (n, m) = map(int, raw_input().split())
        ps = []
        for i in xrange(m):
            ps.append(raw_input())

        print solve(n, m, ps)
