INF = 10 ** 10

def do_check(ns, m, k, u):
    n = len(ns)
    for i in xrange(n):
        if ns[i] < m:
            for j in xrange(u):
                ns[(i + j) % n] = INF
            k -= 1
            if k < 0:
                return False
    return min(ns) >= m

def check(ns, m, k, u):
    n = len(ns)
    for i in xrange(u):
        ms = ns[:]

        for i in xrange(i - u + 1, i + 1):
            ms[i] = INF

        if do_check(ms, m, k - 1, u):
            return True
    return False

def solve(n, k, u, ns):
    l, r = min(ns), max(ns)

    idx = ns.index(l)
    ns = ns[idx:] + ns[:idx]

    while l <= r:
        m = (l + r) >> 1
        
        if check(ns, m, k, u):
            l = m + 1
        else:
            r = m - 1
    return r

assert solve(8, 2, 3, [8, 1, 9, 2, 3, 4, 7, 5]) == 7

if __name__ == '__main__':
    (n, m, l) = map(int, raw_input().split())
    ns = map(int, raw_input().split())

    print solve(n, m, l, ns)
