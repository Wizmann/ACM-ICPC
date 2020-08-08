def solve(ns):
    ns.sort()
    n = len(ns)
    for i in xrange(1, n):
        if ns[i] - ns[i - 1] > 1:
            return False
    return True

assert solve([1, 2]) == True
assert solve([1, 3, 4, 4]) == False
assert solve([100]) == True

T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())

    print 'YES' if solve(ns) else 'NO'

