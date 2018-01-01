def C(n, m):
    res = 1
    for i in xrange(n):
        res *= m - i
        res /= i + 1
    return res

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        print 'Case #%d:' % (case_ + 1),
        n, m = map(int, raw_input().split())

        if n < m + 1:
            print 0.00
            continue

        dp = {(1, 0): 1}
        for i in xrange(2, n + 1):
            for j in xrange(0, m + 1):
                if j >= i:
                    continue
                dp[(i, j)] = 0
                dp[(i, j)] += dp.get((i - 1, j), 0)
                dp[(i, j)] += dp.get((i, j - 1), 0)

        FACTOR = 10 ** 10
        res = FACTOR * dp[(n, m)] / C(min(n, m), n + m)
        print '%.10f' % (1.0 * res / FACTOR)
        
