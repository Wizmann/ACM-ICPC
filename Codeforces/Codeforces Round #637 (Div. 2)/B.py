
def solve(n, k, ns):
    def isPeak(pos):
        return ns[pos - 1] < ns[pos] and ns[pos] > ns[pos + 1]

    peaks = 0
    for i in xrange(1, k - 1):
        if isPeak(i):
            peaks += 1
    mini, minp = peaks + 1, 0
    for i in xrange(k, n):
        p = i - k + 1
        # print '>>', p
        if isPeak(p):
            # print p + 1, '>> 1'
            peaks -= 1
        if isPeak(i - 1):
            # print i - 1, '>> 2'
            peaks += 1

        # print peaks
        if peaks + 1 > mini:
            mini = peaks + 1
            minp = p
    return mini, minp

assert solve(8, 6, [1, 2, 4, 1, 2, 4, 1, 2]) == (3, 1)

T = int(raw_input())
for case_ in xrange(T):
    (n, k) = map(int, raw_input().split())
    ns = map(int, raw_input().split())
    (t, l) = solve(n, k, ns)
    print t, l + 1
