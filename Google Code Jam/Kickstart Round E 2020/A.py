INF = 10 ** 10

def solve(ns):
    n = len(ns)
    ds = []
    for i in xrange(1, n):
        ds.append(ns[i] - ns[i - 1])
    pre = -INF
    cnt = 0
    res = 0
    for num in ds:
        if num == pre:
            cnt += 1
        else:
            res = max(res, cnt + 1)
            pre = num
            cnt = 1
    res = max(res, cnt + 1)
    return res
    
T = int(raw_input())
for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())
    print 'Case #%d: %d' % (case_ + 1, solve(ns))
