def solve(n, e, ns):
    ns.sort()
    h = 0
    res = 0
    while ns:
        if e > ns[0]:
            h += 1
            e -= ns[0]
            ns.pop(0)
        elif h > 0:
            e += ns.pop()
            h -= 1
        else:
            ns.pop()
        res = max(res, h)
    return res

assert solve(1, 100, [100]) == 0
assert solve(3, 10, [20, 3, 15]) == 1

if __name__ == '__main__':
    T = int(raw_input())

    for case_ in xrange(T):
        print 'Case #%d:' % (case_ + 1),

        (e, n) = map(int, raw_input().split())
        ns = map(int, raw_input().split())

        print solve(n, e, ns)
