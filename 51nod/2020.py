def numsort(n, reverse=False):
    return int(''.join(sorted(str(n), reverse=reverse)))

T = int(raw_input())

for case_ in xrange(T):
    (n, k) = map(int, raw_input().split())
    for i in xrange(k):
        u, v = numsort(n), numsort(n, reverse=True)
        n = abs(u - v)
    print abs(n)
