def solve(ns, k):
    n = len(ns)
    tot = 1
    for i in xrange(k):
        tot += ns[i]
    res = []
    pre = tot
    for i in xrange(k, n):
        a = ns[i - k]
        b = ns[i]
        if a > b:
            # tot = tot / a * b
            tot = tot - 1
        elif a < b:
            tot = tot + 1
        else:
            pass
        if tot > pre:
            res.append(True)
        else:
            res.append(False)
        pre = tot
    return res

assert solve([1001, 869120, 1001], 2) == [False]
assert solve([96, 98, 95, 100, 20], 3) == [True, False]
assert solve([3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9], 7) == [True, True, False, True, True, False, True, True]


n, k = map(int, raw_input().split())
ns = map(int, raw_input().split())

res = solve(ns, k)
for item in res:
    print 'Yes' if item else 'No'


