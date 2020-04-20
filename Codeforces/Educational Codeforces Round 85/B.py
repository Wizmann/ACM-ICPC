def solve(ns, x):
    n = len(ns)
    ns.sort(reverse=True)
    
    tot = 0
    maxi = 0
    for i in xrange(n):
        tot += ns[i]
        if tot >= x * (i + 1):
            maxi = max(maxi, i + 1)
    return maxi

T = int(raw_input())

for case_ in xrange(T):
    (n, x) = map(int, raw_input().split())
    ns = map(int, raw_input().split())

    print solve(ns, x)
