def solve(n, k, ks):
    res = []
    ns = range(1, n + 1)
    for i in xrange(k):
        n = len(ns)
        a = (ks[i]) % n
        res.append(ns[a])
        ns = ns[a + 1:] + ns[:a]
    return res

assert solve(7, 5, [10, 4, 11, 4, 1]) == [4, 2, 5, 6, 1]
assert solve(3, 2, [2, 5]) == [3, 2]

if __name__ == '__main__':
    (n, k) = map(int, raw_input().split())
    ns = map(int, raw_input().split())

    print ' '.join(map(str, solve(n, k, ns)))
