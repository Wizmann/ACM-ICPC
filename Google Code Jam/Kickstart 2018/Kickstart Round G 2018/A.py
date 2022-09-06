from collections import defaultdict
from multiprocessing import Pool
import copy

def solve(ns):
    z = len(filter(lambda x: x == 0, ns))
    ns = sorted(filter(lambda x: x, ns))
    n = len(ns)
    maxi = -1 if not ns else max(ns)

    res = 0
    for i in xrange(n):
        d = defaultdict(list)
        for j, num in enumerate(ns):
            if j > i:
                d[num].append(j)

        for key in d.keys():
            d[key] = d[key][::-1]

        for j in xrange(i + 1, n):
            u = ns[i] * ns[j]
            if u > maxi:
                break
            while d[u] and d[u][-1] <= j:
                d[u].pop()
            res += len(d[u])

    if z >= 2:
        res += z * (z - 1) / 2 * n
        res += z * (z - 1) * (z - 2) / 6

    return res


if __name__ == '__main__':
    T = int(raw_input())
    cases = []
    for case_ in xrange(T):
        n = int(raw_input())
        ns = map(int, raw_input().split())
        cases.append(ns)

    p = Pool(4)
    res = p.map(solve, cases)
    for i, ans in enumerate(res):
        print 'Case #%d: %d' % (i + 1, ans)

