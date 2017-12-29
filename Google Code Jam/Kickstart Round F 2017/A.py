def half(x):
    return (x - 1) / 2

def solve(ns):
    n = len(ns)
    p, q = half(n), half(n) + 1

    ms = sorted(ns[:])

    while 0 <= p < n and 0 <= q < n:
        np, nq = p + 1, n - q
        if np >= nq:
            cur = ns[p]
            p -= 1
        else:
            cur = ns[q]
            q += 1

        if cur == ms[-1]:
            ms.pop()
        elif cur == ms[0]:
            ms.pop(0)
        else:
            return False
    return True

assert solve([1, 4, 3, 2]) == True
assert solve([2, 1, 3, 4]) == False
assert solve([2, 1]) == True
assert solve([1, 2, 3]) == False

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        ns = map(int, raw_input().split())

        print 'Case #%d:' % (case_ + 1),
        print 'YES' if solve(ns) else 'NO'
