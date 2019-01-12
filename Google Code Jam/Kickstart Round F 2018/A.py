def solve(a, b):
    s = set()

    n = len(a)
    assert len(a) == len(b)

    for i in xrange(n):
        for j in xrange(i + 1, n + 1):
            u = b[i: j]
            u = ''.join(sorted(u))
            s.add(u)

    res = 0
    for i in xrange(n):
        for j in xrange(i + 1, n + 1):
            u = a[i: j]
            u = ''.join(sorted(u))
            if u in s:
                res += 1

    return res

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        print 'Case #%d: ' % (case_ + 1),
        n = int(raw_input())
        a, b = raw_input(), raw_input()
        print solve(a, b)
