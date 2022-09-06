def judge(ns, k, score):
    n = len(ns)
    cost = 0
    for i in xrange(1, n):
        pre = ns[i - 1]
        cur = ns[i]

        if cur - pre > score:
            cost += (cur - pre - 1) / score

        if cost > k:
            return False
    return True

def solve(ns, k):
    l, r = 1, 10 ** 10
    while l <= r:
        m = (l + r) >> 1
        if judge(ns, k, m):
            r = m - 1
        else:
            l = m + 1
    return l

assert judge([100, 200, 230], 1, 50)
assert solve([100, 200, 230], 1) == 50
assert solve([10, 13, 15, 16, 17], 2) == 2
assert solve([9, 10, 20, 26, 30], 6) == 3
assert solve([1, 2, 3, 4, 5, 6, 7, 10], 3) == 1

T = int(raw_input())

for case_ in xrange(T):
    (n, k) = map(int, raw_input().split())

    ns = map(int, raw_input().split())
    ns.sort()

    print 'Case #%d: %d' % (case_ + 1, solve(ns, k))
