T = int(raw_input())

for case_ in xrange(T):
    (n, k) = map(int, raw_input().split())
    ns = sorted(map(int, raw_input().split()))
    
    cnt = 0
    for num in ns:
        if k >= num:
            k -= num
            cnt += 1
        if k == 0:
            break
    assert k >= 0
    print 'Case #%d: %d' % (case_ + 1, cnt)
